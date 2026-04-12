#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    vector<int> y(x);
    sort(y.begin(), y.end());
    for(int i = 0; i < n; i++){
        if(x[i] <= y[(n-2)/2]) cout << y[n/2] << endl;
        else                   cout << y[(n-2)/2] << endl;
    }
    return 0;
}