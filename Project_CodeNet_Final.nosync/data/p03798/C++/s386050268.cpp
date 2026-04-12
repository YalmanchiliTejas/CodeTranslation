#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int n; string s;
vector<int> a;

void make(){
	for(int i = 1; i <n-1; ++i){
		int l=i-1, r=i+1;
		if(a[i]==0){
		  if(s[i]=='o'){a[r]=a[l];}
		  else{a[r]=(a[l]+1)%2;}
		}
		else{
			if(s[i]!='o'){a[r]=a[l];}
		    else{a[r]=(a[l]+1)%2;}
        }
    }
}

bool check(int l, int c, int r){
	if(a[c]==0){
		if(s[c]=='o' && a[l]!=a[r])return false;
		if(s[c]!='o' && a[l]==a[r])return false;
    }
    else{
    	if(s[c]!='o' && a[l]!=a[r])return false;
        if(s[c]=='o' && a[l]==a[r])return false;
    }
    return true;
}

int main(){
	cin >> n >> s;
    a.resize(n);
	for(int t = 0; t < 4; ++t){
		if(t==0){a[0]=0;a[1]=0;}
		if(t==1){a[0]=1;a[1]=0;}
		if(t==2){a[0]=0;a[1]=1;}
		if(t==3){a[0]=1;a[1]=1;}
		make();
		if(check(n-2, n-1,0) && check(n-1, 0, 1)){
			for(int i = 0; i < n; ++i){
				if(a[i]==0)cout << 'S';
				else cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
}
