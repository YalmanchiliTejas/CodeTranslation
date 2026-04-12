#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

int main()
{
    char n;
    cin >> n;
    if(n=='a'||n=='e'||n=='i'||n=='o'||n=='u'){
        cout<<"vowel"<<endl;
    }else{
        cout<<"consonant"<<endl;
    }
    return 0;
}