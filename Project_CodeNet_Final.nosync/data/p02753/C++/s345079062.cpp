#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
int main(){
    int n;
    string s;
    while(cin>>s){
        ll ans=0;
        for(int i=0; i<2; ++i){
        	if(s[i]!=s[i+1]){
        		ans=1;
        	}
        }
        if(ans){
        	cout<<"Yes"<<endl;
        }
        else{
        	cout<<"No"<<endl;
        }
    }
  return 0;
}


