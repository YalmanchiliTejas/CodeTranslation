#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
    while(true){
        int N;
        cin>>N;
        if(N==0) break;
        stack<int> bla;
        stack<int> whi;
        bla.push(-1);
        whi.push(-1);
        for(int i=1;i<=N;i++){
            int a;
            cin>>a;
            if(i%2==0){
                int B=bla.top();
                int W=whi.top();
                if(a==1){
                    if(B==-1){
                        bla.push(1);
                        if(!whi.empty()) whi.pop();
                    }else{
                        if(B<W){
                            whi.pop();
                        }
                    }
                }else{
                    if(W==-1){
                        whi.push(1);
                        if(!bla.empty()) bla.pop();
                    }else{
                        if(W<B){
                            bla.pop();
                        }
                    }
                }
            }else{
                int B=bla.top();
                int W=whi.top();
                if(a==1){
                    if(B==-1){
                        bla.push(i);
                    }else{
                        if(B<W){
                            bla.push(i);
                        }
                    }
                }else{
                    if(W==-1){
                        whi.push(i);
                    }else{
                        if(W<B){
                            whi.push(i);
                        }
                    }
                }
            }
        }
        bla.push(N+1);
        int ans=0;
        int now=N+1;
        while(true){
            int B=bla.top();
            int W=whi.top();
            if(B==-1 && W==-1) break;
            if(B<W){
                ans+=now-W;
                now=W;
                whi.pop();
            }else{
                now=B;
                bla.pop();
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}