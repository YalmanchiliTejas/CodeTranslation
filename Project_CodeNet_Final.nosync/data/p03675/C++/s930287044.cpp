#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> odd((n+1)/2);
    vector<int> even(n/2);
    for(int i = 0;i < (n+1)/2;i++){
        cin >> odd[i];
        if(i < (n+1)/2 -1  | n%2 == 0) cin >> even[i];
    }
    vector<int> v;
    if(n%2 == 0){
        reverse(even.begin(),even.end());
        even.insert(even.end(), odd.begin(), odd.end());
        v = even;
    }
    else{
        reverse(odd.begin(), odd.end());
        odd.insert(odd.end(), even.begin(), even.end());
        v = odd;
    }
    for(int i = 0;i < n-1; i++){
        cout << v[i] << " ";
    }
    cout << v[n-1] << endl;
    return 0;
}