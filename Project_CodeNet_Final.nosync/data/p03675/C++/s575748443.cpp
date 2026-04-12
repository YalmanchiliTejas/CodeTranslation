#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define endl '\n'
typedef long long ll;
typedef long double ld;

int a[200000+10];

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    rep(i,0,n){
    	cin>>a[i];
    }
    if(n%2==0){
    	int i = n/2;
    	rep(j,0,i){
    		cout<<a[(2*(i-j))-1]<<" ";
    	}
    	rep(j,i,n){
    		cout<<a[2*(j-i)]<<" ";
    	}
    }	
    else{
    	int i = n/2;
    	rep(j,0,i){
    		cout<<a[(2*(i-j))]<<" ";
    	}
    	cout<<a[0]<<" ";
    	rep(j,i+1,n){
    		cout<<a[(2*(j-i))-1]<<"	 ";
    	}
    }
    cout<<endl;
}