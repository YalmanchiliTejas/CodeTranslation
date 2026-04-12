
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int main(){
    string s;
    cin >> s;
    rep(i, s.size() - 1){
        if(s[i] == 'A' && s[i + 1] == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
