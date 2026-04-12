#include <iostream>
#include <bits/stdc++.h>
using namespace std;
deque<int> d1;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i==1){
            d1.push_front(x);
        }
        else if(i%2==0){
            d1.push_front(x);
        }else{
            d1.push_back(x);
        }
    }
    if(!(n%2)){
        for(int i=0;i<d1.size();i++){
            cout<<d1[i]<<" ";
        }
    }else{
        for(int i=d1.size()-1;i>=0;i--){
            cout<<d1[i]<<" ";
        }
    }
}
