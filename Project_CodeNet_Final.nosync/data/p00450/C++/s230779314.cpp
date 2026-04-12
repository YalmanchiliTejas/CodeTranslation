#include<iostream>
#include<stack>
#include<vector>
#define reep(a,s,d) for(int a=d;a<s;a++)
#define rep(a,s) reep(a,s,0)
using namespace std;
stack<int> B;
stack<int> W;
int main(){
    int n;
    while(cin>>n,n){
        int w=0,b=0;
        reep(i,n+1,1){
            bool c;
            cin>>c;
            if(c){
                if(i%2){
                    if(b>0)b++;
                    else{
                        W.push(w);
                        w=0;
                        b++;
                    }
                }else{
                    if(b>0)b++;
                    else{
                        b=w+1;
                        if(!B.empty()){
                            b+=B.top();
                            B.pop();
                        }
                        w=0;
                    }
                }
            }else{
                if(i%2){
                    if(w>0)w++;
                    else{
                        B.push(b);
                        b=0;
                        w++;
                    }
                }else{
                    if(w>0)w++;
                    else{
                        w=b+1;
                        if(!W.empty()){
                            w+=W.top();
                            W.pop();
                        }
                        b=0;
                    }
                }
            }
        }
        while(!W.empty()){
            w+=W.top();W.pop();
        }
        cout<<w<<endl;
        while(!B.empty())B.pop();
    }
}