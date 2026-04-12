#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int ll;
#define rep(i, n) for(int i=0;i< int (n);i++)

int main(void)
{
    int Q;    
    int  b;
    string n;
    bool ques = true;
    
    cin >> n;

    if (n[0] != n[1])
    {
        cout << "Yes" << endl;
        return 0;
    }
    else if (n[1] != n[2])
    {
        cout << "Yes" << endl;
        return 0;
    }
    else
    {
        cout << "No" << endl;
        return 0;
    }
        
   
}

   