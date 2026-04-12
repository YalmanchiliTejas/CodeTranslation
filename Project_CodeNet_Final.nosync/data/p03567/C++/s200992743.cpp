#include<iostream>
#include <algorithm>
#include <string>
#include<math.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
int main() {
    string a;
    cin >> a;
    if (a[0] == 'A'&&a[1] == 'C') {
        cout << "Yes" << endl;
        return 0;
    }
    if (a[1] == 'A'&&a[2] == 'C') {
        cout << "Yes" << endl;
        return 0;
    }
    if (a[2] == 'A'&&a[3] == 'C') {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
