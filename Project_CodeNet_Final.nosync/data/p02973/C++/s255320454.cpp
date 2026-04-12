#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> s;
    s.insert(a[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
        auto p = s.upper_bound(a[i]);
        if(p == s.end())
            s.insert(a[i]);
        else {
            s.erase(p);
            s.insert(a[i]);
        }
    }
    cout << s.size() << endl;
    return 0;
}