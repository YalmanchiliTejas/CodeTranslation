#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int> h;
    int dum;
    int cnt =0;
    for(int i=0; i<n;i++){
        cin >> dum;
        h.push(dum);
        if(h.top() == dum) cnt++;
    }
    cout <<cnt<<endl;
}