#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(){
    int n=1;
    while (true){
        cin >> n;
        if(n==0) break;
        vector<int> a(n);
        for (int i = 0 ;i<n;i++){
            cin >> a[i];
         }
        sort(a.begin(),a.end());
        int sum=0;
        for (int i=1;i<n-1;i++){
            sum+=a[i];
        }
        cout << sum /(n-2)<<endl;
    }
}