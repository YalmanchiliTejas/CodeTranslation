#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    char c;
    cin>>c;
    vector<char> v = {'a','e','i','o','u'};

    cout<< ((find(v.begin(), v.end(),c)!=v.end()) ? "vowel": "consonant")<<endl;

    return 0;
}