#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k; string s;
    cin >> n >> s >> k;
    char tgt = s[k-1];
    for(auto i = s.begin();i!=s.end();++i) {
        if(*i!=tgt) cout << "*";
        else cout << *i;
    }
    cout << endl;
    return 0;
}