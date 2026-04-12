#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    int n;
    cin >> n;
    int x[n],num[n];
    
    for(int i = 0;i < n;i++)cin >> x[i];
    for(int i = 0;i < n;i++)num[i] = x[i];
    sort(num,num+n);
    
    for(int i = 0;i < n;i++){
        
        if(x[i] >= num[n/2]){
            cout << num[n/2-1];
        } else if(x[i] < num[n/2]){
            cout << num[n/2];
        }
        
        cout << endl;
        
    }
    
}