#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
    int N,max,t;
    cin >>N;
    vector<int> mt(N);
    for(int i=0;i<N;i++){
        cin >>mt.at(i);
    }
    t=1;
    max=mt.at(0);
    for(int i=1;i<N;i++){
        if(mt.at(i)>=max){
            t +=1;
            max =mt.at(i);
        }
    }
    cout << t <<endl;
}