#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a=(n-n%15)/15;
	cout<<n*800-a*200<<endl;
}
