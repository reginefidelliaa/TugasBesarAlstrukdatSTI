#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S){
    S->Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas CAPACITY */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S){
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S){
    return S.Count == CAPACITY;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai CAPACITY */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, ElType Elmt){
    if (IsMemberSet(*S, Elmt))
    {
        return;
    }
    S->Elements[S->Count] = Elmt;
    S->Count++;
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, ElType Elmt){
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMemberSet(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (S->Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->Elements[iterator - 1] = S->Elements[iterator];
    }
    S->Count--;
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, ElType Elmt){
    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (S.Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */

Set SetUnion(Set s1, Set s2){
    Set s3;
    CreateEmptySet(&s3);
    for(int i = 0; i<s1.Count; i++){
        InsertSet(&s3, s1.Elements[i]);
    }
    for(int i = 0; i<s2.Count; i++){
        InsertSet(&s3, s2.Elements[i]);
    }
    return s3;
}
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

Set SetIntersection(Set s1, Set s2){
    Set s3;
    CreateEmptySet(&s3);
    for(int i = 0; i<s1.Count; i++){
        if(IsMemberSet(s2, s1.Elements[i])){
        InsertSet(&s3, s1.Elements[i]);
        }
    }
    return s3;
}
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set s1, Set s2){
    Set s3;
    CreateEmptySet(&s3);
    for(int i = 0; i<s1.Count; i++){
        if(!IsMemberSet(s2, s1.Elements[i])){
        InsertSet(&s3, s1.Elements[i]);
        }
    }
    for(int i = 0; i<s2.Count; i++){
        if(!IsMemberSet(s1, s2.Elements[i])){
        InsertSet(&s3, s2.Elements[i]);
        }
    }
    return s3;
}
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

Set SetSubtract(Set s1, Set s2){
    Set s3;
    CreateEmptySet(&s3);
    for(int i = 0; i<s1.Count; i++){
        if(!IsMemberSet(s2, s1.Elements[i])){
        InsertSet(&s3, s1.Elements[i]);
        }
    }
    return s3;
}
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]