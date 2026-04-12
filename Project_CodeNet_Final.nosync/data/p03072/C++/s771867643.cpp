#include <bits/stdc++.h>    //vectorを使う
using namespace std;


int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i < n; ++i){
        cin >> h.at(i);
    }
    int max=0;
    int num=0;
    for(int i=0; i < n; ++i){
        if(h.at(i)>=max){
            num=num+1;
            max=h.at(i);
        }else{}
    }
    cout << num << endl;
}