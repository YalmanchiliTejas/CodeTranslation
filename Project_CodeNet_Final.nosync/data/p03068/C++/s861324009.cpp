#include<bits/stdc++.h>
#define all(x) (x).begin() , (x).end()
#define ll long long 
#define pb push_back
#define mp make_pair


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n ; cin>>n;
    string s ; cin>>s;
    int k ; cin>>k;
    char c = s[k - 1];
    for(int i = 0  ; i < n ; ++i){
      if(s[i] != c)s[i] = '*';
    }
    cout<<s<<endl;

}
