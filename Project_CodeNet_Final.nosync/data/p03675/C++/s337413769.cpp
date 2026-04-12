#include <iostream>
using namespace std;

int n;
int A[200010],B[200010];
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> A[i];
	}
	int a = 1,b = n,count = 0;
	for(int i=n;i>0;i--){
		if(count%2==0){
			B[a] = A[i];
			a++;
		}else{
			B[b] = A[i];
			b--;
		}
		count++;
	}
	for(int i=1;i<=n;i++){
		if(i!=n) cout << B[i] << " ";
		else cout << B[i] << endl;
	}
}