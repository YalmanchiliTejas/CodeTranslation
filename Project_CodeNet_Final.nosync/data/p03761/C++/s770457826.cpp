#include <bits/stdc++.h> 
using namespace std;
const long INF=1000000000000000;
const long MOD=1000000007;

int main(){
    long n;
    cin>>n;
    vector<string> S(n);
    for(int i=0;i<n;i++) cin>>S.at(i);
    for(int i=0;i<26;i++){
        long m=INF;
        char x='a'+i;
        for(int j=0;j<n;j++){
            long pre=0;
            for(int l=0;l<S.at(j).size();l++) pre+=(S.at(j).at(l)==x);
            m=min(m,pre);
        }
        while(m>0){
            cout<<x;
            m--;
        }
    }
    cout<<endl;
}
