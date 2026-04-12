#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        a.push_back(x);
    }
    copy(a.begin(), a.end(), back_inserter(b));
    sort(b.begin(), b.end());
    int left = b[n/2-1], right = b[n/2];
    
    for(int i=0;i<n;i++){
        if(a[i]<=left){
            cout << right << endl;
        } else {
            cout << left << endl;
        }
    }
}