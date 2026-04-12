#include <iostream>
using namespace std;
int main(){
	int panjangstring;
	cin >> panjangstring;
	char stringnya[panjangstring];
	cin >> stringnya;
	int huruf_yang_mau_dihapus;
	cin >> huruf_yang_mau_dihapus;
	huruf_yang_mau_dihapus = huruf_yang_mau_dihapus - 1;
	char hurufdihapus = stringnya[huruf_yang_mau_dihapus];
	//cout << hurufdihapus;
	for(int i = 0 ; i < panjangstring ; i++){
		if (hurufdihapus != stringnya[i]){
			stringnya[i] = '*';
		}
	}
	cout << stringnya << endl;
}