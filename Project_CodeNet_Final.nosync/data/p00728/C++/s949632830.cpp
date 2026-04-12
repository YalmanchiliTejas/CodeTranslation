#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main(){
    while( true ){
        int n;
        int ma = 0;
        int mi = 1000;
        int s = 0;
        cin >> n;

        if(n == 0){
            break;
        }

        int a[n];

        for(int i=0;i<n;i++){
            cin >> a[i];
            if(ma < a[i]){
                ma = a[i];
            }
            if(mi > a[i]){
                mi = a[i];
            }
            s += a[i];
        }

        cout << (s - ma - mi)/(n - 2) << endl;
    }   
 
}