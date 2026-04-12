#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))

vector<string> split(string,string);

//template<typename T>
//void swap(T*,T*);
//char ToUpper (char cX) { return toupper(cX); }

int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    int sum;
    sum = 100 * x + 10 * y + z;
    if(sum % 4 == 0)
    {
        Yes(true);
    }else
    {
        Yes(false);
    }
}