#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
    deque<int> dq;
    if(n%2){
        for(int i=0;i<n;++i){
            int a;cin>>a;
            if(i%2)dq.push_back(a);
            else dq.push_front(a);
        }
    }else{
        for(int i=0;i<n;++i){
            int a;cin>>a;
            if(i%2==0)dq.push_back(a);
            else dq.push_front(a);
        }
    }
    cout<<dq[0];
    for(int i=1;i<n;++i){
        cout<<" "<<dq[i];
    }
    cout<<endl;
}