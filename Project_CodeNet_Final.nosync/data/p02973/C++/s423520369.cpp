# include <iostream>
# include <set>
#include <algorithm>
#include <math.h>
# include<map>
typedef long long ll;
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    multiset<int> m;
    for (int i=0; i<n; i++) {
        multiset<int> :: iterator it = m.lower_bound(arr[i]);
        if (it == m.begin()) {
            m.insert(arr[i]);
        } else {
            it--;
            m.erase(it);
            m.insert(arr[i]);
        }
    }
    cout << m.size() << endl;
    return 0;
}