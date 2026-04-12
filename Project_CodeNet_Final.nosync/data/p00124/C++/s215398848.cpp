// Tazoe

#include <iostream>
#include <string>
using namespace std;

int main()
{
bool flg = false;
while(true){
	int n;
	cin >> n;
if(n==0)  break;
	string T[10];
	int P[10];
	int I[10];
	for(int i=0; i<n; i++){
		cin >> T[i];

		int w, l, d;
		cin >> w >> l >> d;
		P[i] = w*3+d;

		I[i] = i;
	}

	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(P[i]<P[j]||(P[i]==P[j]&&I[i]>I[j])){
				string s_tmp = T[i];
				T[i] = T[j];
				T[j] = s_tmp;

				int tmp = P[i];
				P[i] = P[j];
				P[j] = tmp;

				tmp = I[i];
				I[i] = I[j];
				I[j] = tmp;
			}
		}
	}

if(flg)
cout << endl;
else
flg = true;

	for(int i=0; i<n; i++){
		cout << T[i] << ',' << P[i] << '\n';
	}
}
	return 0;
}