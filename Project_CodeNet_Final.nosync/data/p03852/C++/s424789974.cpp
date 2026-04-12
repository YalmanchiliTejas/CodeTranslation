#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define llong long long int
#define ullong unsigned long long int

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c[1]; cin >> c[0];
    cout << ((c[0]=='a'||c[0]=='i'||c[0]=='u'||c[0]=='e'||c[0]=='o') ? "vowel" : "consonant") << endl;

    return 0;
}