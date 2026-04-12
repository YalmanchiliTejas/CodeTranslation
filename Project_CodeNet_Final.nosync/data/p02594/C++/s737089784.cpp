#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define ii pair<int,int> 
#define f first
#define s second
#define pb push_back

int r,c;
int v[999][18278];
map<ii,string> m;

ii id(string s){
    int ten=1;
    int ts=1;
    int x=0,y=0;
    for(int i=s.length()-1;i>=0;i--){
        if(isdigit(s[i])){
           x+= (s[i]-48)*ten;
           ten*=10;
        }
        else if(isalpha(s[i])){
            y+= (s[i]-65)*ts;
            ts*=26;
        }
    }
    x--;
    y--;
    return make_pair(x,y);
}
int cal(int i,int j){
    
    if(v[i][j]!=INT_MAX)return v[i][j];
    string s = m[{i,j}];
    string ip;
    istringstream iss(s);
    int ans=0;
    while(getline(iss,ip,'+')){
        ii loc = id(ip);
        ans+=cal(loc.f,loc.s);
    }
    v[i][j]=ans;
    return ans;
    
}
int32_t main(){
    int t;
    cin>>t;
    if(t>=30)cout<<"Yes";
  else cout<<"No";
}