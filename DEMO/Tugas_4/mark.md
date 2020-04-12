## Constraint Satisfaction Problem (CSP)

CSP adalah pertanyaan matematis yang didefinisikan sebagai sekumpulan objek
yang kondisinya harus memenuhi sejumlah kendala atau batasan. CSP mewakili 
entitas dalam masalah sebagai kumpulan homogen dari batasan hingga variabel, 
yang diselesaikan dengan metode kepuasan kendala. CSP adalah subjek penelitian 
intensif dalam kecerdasan buatan dan penelitian operasi, karena keteraturan 
dalam formulasi mereka memberikan dasar umum untuk menganalisis dan memecahkan 
masalah yang tampaknya tidak terkait.

Propagation yaitu setiap kali pemecah memberikan nilai ke variabel, 
kendala menambahkan batasan pada nilai yang mungkin dari variabel 
yang tidak ditetapkan. Pembatasan ini menyebar ke penugasan variabel 
masa depan. Misalnya, dalam masalah 4-queens, setiap kali pemecah 
menempatkan ratu, ia tidak dapat menempatkan ratu lain di baris dan 
diagonal ratu saat ini aktif. Propagasi dapat mempercepat pencarian 
secara signifikan dengan mengurangi sekumpulan nilai variabel yang 
harus dieksplorasi oleh pemecah.

Backtracking occurs yaitu ketika solver tidak dapat memberikan nilai 
ke variabel berikutnya, karena kendala, atau ia menemukan solusi. 
Dalam kedua kasus tersebut, pemecah melakukan backtracks ke tahap 
sebelumnya dan mengubah nilai variabel pada tahap itu ke nilai yang 
belum pernah dicoba. Dalam contoh 4-queens, ini berarti memindahkan 
ratu ke kotak baru pada kolom saat ini.

```c
#include <bits/stdc++.h> 
#define MAX 10 
using namespace std; 

int arr[MAX], no; 

bool canPlace(int k, int i){ 
	for (int j = 1;j <= k - 1;j++){ 
		if (arr[j] == i || 
			(abs(arr[j] - i) == abs(j - k))) 
		return false; 
	} 
	return true; 
} 
```
Untuk mengecek apakah tempat tersebut bisa ditempati Queen 
(sesuai problem, bahwa Queen tidak boleh saling bunuh)
```c
void display(int n){ 
	cout << "\n---------------------------------\n"; 
	cout << "Arrangement No. " << ++no; 
	cout << "\n---------------------------------\n";
	for (int i = 1; i <= n; i++){ 
		for (int j = 1; j <= n; j++){ 
			if (arr[i] != j) 
				cout << "    X"; 
			else
				cout << "    Q"; 
		} 
		cout << endl; 
	} 
	cout << "\n---------------------------------\n";
} 
```
Untuk print Queen pada board 

```c
void nQueens(int k, int n){ 
	for (int i = 1;i <= n;i++){ 
		if (canPlace(k, i)){ 
			arr[k] = i; 
			if (k == n) 
				display(n); 
			else
				nQueens(k + 1, n); 
		} 
	} 
} 
```
Fungsi untuk mengecek tempat yang akan ditempati oleh queen.
```c
int main(){ 
	int n = 4;	 
	nQueens(1, n);	 
	return 0; 
} 
```
Fungsi main dari program
