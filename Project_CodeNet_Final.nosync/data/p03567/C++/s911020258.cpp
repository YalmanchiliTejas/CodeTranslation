#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0; i< int(n); (i)++)

int main()
{
    char a[6]={0};
    cin >> a;
    REP(i,5)
    {
        if(a[i]=='A' && a[i+1]=='C')
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}