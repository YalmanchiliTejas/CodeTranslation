#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int k;
    int a;
    int h=1;
    cin >> k;
    for(int i=0;i<n-1;i++){
        cin>>a;
        if(k<=a)h++;
        k=max(k,a);
    }
    cout << h << endl;
    return 0;
}