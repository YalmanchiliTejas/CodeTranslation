#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

int main(void){
    string s,t="yuiophjklnm";
    while(cin>>s,s!="#"){
        int c=-1,a=0;
        for(auto p:s){
            int tmp=t.find(p)!=string::npos?1:0;
            if(tmp!=c&&c!=-1)a++;
            c=tmp;
        }
        cout<<a<<endl;
    }
}