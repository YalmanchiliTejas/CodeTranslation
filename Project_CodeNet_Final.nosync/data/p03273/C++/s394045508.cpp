#include <bits/stdc++.h>
using namespace std;
#define pair pair<int,int>
#define ll long long

int x,y;
string a[110];
bool okx[110],oky[110];

int main(){
    cin >> x >> y;
	for(int i=0;i<x;i++){
		cin >> a[i];
	}
	for(int i=0;i<x;++i){
		for(int j=0;j<y;++j){
			if(a[i][j]=='#'){
				okx[i]=true;
				oky[j]=true;
			}
		}
	}
	for(int i=0;i<x;++i){
		if(okx[i]){
			for(int j=0;j<y;++j){
				if(oky[j]) cout << a[i][j];
			}
			cout << endl;
		}
	}
}