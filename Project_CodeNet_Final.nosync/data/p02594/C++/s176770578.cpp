// Vivek Rai
// Blazer_007

#include<bits/stdc++.h>
using namespace std;

#define fastio    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl      '\n'

typedef long long int ll;
const int hell = 1e9 + 7 ;

istream &operator>>(istream &in, vector<int> &arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
    	cin >> arr[i];
    return in;
}

ostream &operator<<(ostream &os, vector<int> arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
    return os;
}

signed main() {

    fastio

    int temp;
    cin >> temp;
    if (temp >= 30)
    	cout << "Yes" << endl;
    else
    	cout << "No" << endl;
    return 0;
}