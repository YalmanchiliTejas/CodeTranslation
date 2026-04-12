#include<bits/stdc++.h>
using namespace std;

int N, A, ans = 0, flag = 1;
int a, b, c, d, e, k;
vector<int> v;
int main(){
    cin >> N;
    v.resize(2*N);
	
    for(int i=0; i<N; i++)
	cin >> v[i];
    for(int i=0; i<N; i++){
	flag=1;
	for(int j=0; j<i; j++){
	    if(v[i] < v[j])   
		flag = 0;
	}
	if(flag == 1)
	    ans++;
    }
    cout << ans<< endl;
}
