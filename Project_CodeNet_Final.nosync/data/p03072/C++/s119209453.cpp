#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<string>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    int max_H;
    int cnt=1;
    cin>>max_H;
    for(int i=1;i<N;i++){
        int H;
        cin>>H;
        if(max_H<=H){
            max_H=H;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}