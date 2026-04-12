#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int s;
    cin>>s;
    int arr[s];
    for(int i = 0; i <s;++i){
        cin>>arr[i];
    }

    for(int i = s-1; i >=0; i-=2){
        cout<<arr[i]<<" ";
    }

    for(int i = s%2? 1 : 0 ; i<s; i+=2){
        cout<<arr[i]<<" ";
    }


    return 0;
}
