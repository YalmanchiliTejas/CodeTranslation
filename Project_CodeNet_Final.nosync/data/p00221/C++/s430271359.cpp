#include<bits/stdc++.h>
using namespace std;

string FB(int n){
    if(n%3==0&&n%5==0)return "FizzBuzz";
    if(n%3==0)return "Fizz";
    if(n%5==0)return "Buzz";
    stringstream ss;
    ss<<n;
    return ss.str();
}

int m,n;

void solve(){
    vector<int>rem(m);
    for(int i=0;i<m;i++)rem[i]=i+1;

    int c=0;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(rem.size()==1)continue;
        if(s!=FB(i)){
            rem.erase(remove(rem.begin(),rem.end(),rem[c]),rem.end());
            c%=rem.size();
        }
        else{
            c=(c+1)%rem.size();
        }
    }

    for(int i=0;i<rem.size();i++){
        cout<<(i?" ":"")<<rem[i];
    }
    cout<<endl;
}

int main(){
    while(cin>>m>>n,m||n)solve();
}