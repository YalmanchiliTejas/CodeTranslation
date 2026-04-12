#include <bits/stdc++.h>
using namespace std;


int main (){
    int N;
    cin>>N;
    vector<int> V(N);
    int Count=0;
    int Border=0;
    for(int i=0; i<N; i++){
        cin>>V.at(i);
        if(V.at(i)>Border-1){
            Border=V.at(i);
            Count ++;
        }
    }
    cout<<Count<<endl;
   

}