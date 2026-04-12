#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    int cnt=0;
    for(int i=1;i<n;i++){
        if(h[i]<h[i-1]){
            swap(h[i],h[i-1]);
            cnt++;
        }
    }
    cout << n-cnt << endl;
}