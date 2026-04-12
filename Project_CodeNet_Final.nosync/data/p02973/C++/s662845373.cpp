/////////////////////////////////
//                             //
//           /(.^.)\           //
//                             //
/////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define BYTE unsigned char
#define DWORD unsigned int
#define QWORD unsigned long long
#define LL long long


//デバッグプリント
void xxxcoutxxx(int a, int f = 0)
{
    cout << a << " "; if (f) cout << endl;
    return;
}


//main
int main()
{
    int rtn = 0;
    
    vector<int> ccc;

    ccc.push_back(1);

    int n,a;
    int f;
    
    int st;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a;

        f = 1;

        st = distance(ccc.begin(),upper_bound(ccc.begin(),ccc.end(),-a));
        
        if (st >= ccc.size())
        {
            ccc.push_back(-a);
        }
        else
        {
            for (int ii = st; ii < ccc.size(); ++ii)
            {
                if (ccc[ii] > -a)
                {
                    ccc[ii] = -a;
                    f = 0;
                    break;
                }
            }

            if (f)
            {
                ccc.push_back(-a);
            }
        }

    }

    rtn = ccc.size();
    cout << rtn;
    return 0;
    cout << "/(.^.)\\" << endl;
}