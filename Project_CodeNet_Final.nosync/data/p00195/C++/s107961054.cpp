#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)
#define all(n) n.begin(),n.end()

int s[5];

int main()
{
    int n1, n2;
    while(cin >> n1 >> n2 && (n1 || n2))
    {
        s[0] = n1 + n2;
        REP(4){cin >> n1 >> n2; s[i+1] = n1 + n2;}
        int m = 0;

        REP(5)if(s[m] < s[i]) m = i;

        cout <<(char)('A' + m) << " " << s[m] << endl;
    }
    
    return 0;
}