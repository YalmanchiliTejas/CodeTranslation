#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int count=1;
    int High;
    cin>>High;
    int H;
    for(int i=2;i<=N;i++){
        cin>>H;
        if(H>=High){count++;High=H;}
    }
    cout<<count<<endl;
}