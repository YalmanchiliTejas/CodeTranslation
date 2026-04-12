#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector< vector<int> > num(26, vector<int>(n));
    for(int i=0; i<n; i++) {
        string S;
        cin >> S;
        for(int j=0; j<S.size(); j++) {
            num[S[j]-'a'][i]++;
        }
    }

    char c = 'a';
    for(auto e: num) {
        int m = *min_element(e.begin(), e.end());
        while(m--) {
            cout << c;
        }
        ++c;
    }
    cout << endl;
    return 0;
}
