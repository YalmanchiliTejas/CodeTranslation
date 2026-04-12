#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using it=std::int64_t;

int main(){
    it n;
    cin>>n;
    std::vector<it> h(n);
    for(it i=0;i<n;i++){
        cin>>h[i];
    }

    it high=0,count=0;
    for(it i=0;i<n;i++){
        if(high<=h[i]){
            count++;
            high=h[i];
        }
    }
    cout<<count<<endl;
}