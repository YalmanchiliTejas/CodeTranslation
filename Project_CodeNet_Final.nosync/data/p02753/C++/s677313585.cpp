#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1666666
int arr[N];
signed main(){
    
    string str;
    cin>>str;
    set<char> s;
    for(int i=0;i<str.size();i++) s.insert(str[i]);
    if(s.size()!=1) cout<<"Yes";
    else  cout<<"No";
    return 0;
}

/*
))((())(

*/