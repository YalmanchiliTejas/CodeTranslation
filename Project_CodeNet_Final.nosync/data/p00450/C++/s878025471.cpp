#include<iostream>
#include<stack>
#include<vector>
#define reep(a,s,d) for(int a=d;a<s;a++)
#define rep(a,s) reep(a,s,0)
using namespace std;
stack<int> S[2];
int main(){
    int n;
    while(cin>>n,n){
        int s[2]={};
        reep(i,n+1,1){
            bool c;
            cin>>c;
            if(i%2){
                if(s[c]>0)s[c]++;
                else{
                    S[c^1].push(s[c^1]);
                    s[c^1]=0;
                    s[c]++;
                }
            }else{
                if(s[c]>0)s[c]++;
                else{
                    s[c]=s[c^1]+1;
                    if(!S[c].empty()){
                        s[c]+=S[c].top();
                        S[c].pop();
                    }
                    s[c^1]=0;
                }
            }
        }
        while(!S[0].empty()){
            s[0]+=S[0].top();S[0].pop();
        }
        while(!S[1].empty())S[1].pop();
        cout<<s[0]<<endl;
    }
}