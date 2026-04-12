#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX


using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(int (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define llong long long
#define debug(x) cout<<#x<<": "<<x<<endl

llong n;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    string c;
    cin >> c;
    if (c == "a" || c == "i" || c == "u" || c == "e" || c == "o")
        cout << "vowel" << endl;
    else cout << "consonant" << endl;

    return 0;
}