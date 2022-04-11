// C++ program to implement  a multilevel linked list

#include <bits/stdc++.h>
using namespace std;

// Representasi  node
class Node {
public:
	int data;
	Node* next;
	Node* child;
};

// Fungsi untuk membuat daftar tertaut
// dengan n(ukuran) node mengembalikan penunjuk kepala
Node* createList(int* arr, int n)
{
	Node* head = NULL;
	Node* tmp;

	// Melintasi array yang dilewati
	for (int i = 0; i < n; i++) {
		// Membuat node jika daftarnya kosong
		if (head == NULL) {
			tmp = head = new Node();
		}
		else {
			tmp->next = new Node();
			tmp = tmp->next;
		}
		// Membuat simpul dengan data dan
        // mengatur anak dan pointer berikutnya
        // sebagai NULL.
		tmp->data = arr[i];
		tmp->next = tmp->child = NULL;
	}
	return head;
}

// Untuk mencetak daftar tertaut
void printMultiLevelList(Node* head)
{
	// menggunakan while jika kepala tidak 0
	while (head) {
		if (head->child) {
			printMultiLevelList(head->child);
		}
		cout << head->data << " ";
		head = head->next;
	}
}

// jalankan kode
int main()
{
	// Initialisasi data dalam arrays(row wise)
	int arr1[3] = { 1, 2, 3 };
	int arr2[2] = { 4, 5 };
	int arr3[1] = { 6 };
	int arr4[3] = { 7, 8, 9 };

	// membuat Empat daftar tertaut
    // Melewati array dan ukuran array
    // sebagai parameter

	Node* head1 = createList(arr1, 3);
	Node* head2 = createList(arr2, 2);
	Node* head3 = createList(arr3, 1);
	Node* head4 = createList(arr4, 3);

	// Initialisasi children dan pointer selanjutnya
	// seperti yang ditunjukkan pada diagram yang diberikan
	head1->child = head2;
	head1->next->next->child = head3;
	head2->next->child = head4;

	// Membuat pointer NULL.
	Node* head = NULL;
	head = head1;

	// // Fungsi Panggilan untuk mencetak
	printMultiLevelList(head);

	return 0;
}
