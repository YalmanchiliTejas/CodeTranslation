#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int count =1;
    cin >>N;
    if(N==1) {
        cout << 1 <<endl;
        return 0;
    }
    vector<int> data(N);
    for (int i=0; i<N;i++){
        cin >> data.at(i);
    }
    if(data.at(0)<=data.at(1)) count =2;
    int s = data.at(0);
    for(int i=1; i<N-1;i++){
        if(s<data.at(i)){
            s=data.at(i);
        }
        if(s<=data.at(i+1)) count++;   
}
cout << count <<endl;
}