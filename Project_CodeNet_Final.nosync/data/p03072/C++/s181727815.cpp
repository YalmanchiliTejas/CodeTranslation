#include <iostream>
using namespace std;

int main(){

int n, k, soma=0,maior=0;
cin >> n;
int vetor[n];

for (int i=0;i<n;i++){
    cin >> k;
    vetor[i]=k;
    if (vetor[i] >=maior){soma++;maior=vetor[i];}
    }

cout << soma << endl;



return 0;
}
