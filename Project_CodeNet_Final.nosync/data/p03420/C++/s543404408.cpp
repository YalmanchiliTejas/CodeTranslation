#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

lint rez;

int n, k;


int cautBin(int nr, int st)
{
    int a = (n - st) / nr;
    int i = st;
    int pas = 1 << 20;
    while(pas != 0)
    {
        if(i + pas < nr && (n - (i + pas)) / nr == a)
            i += pas;

        pas >>= 1;
    }

    return i;
}
/*
map <int, int> aps;

int apx[100001];*/

int main()
{
    cin >> n >> k;

    int i;
    int rez2 = 0;
    for(i = k + 1; i <= n; i ++)
    {
        ///b = i;
        int last = cautBin(i, k);
        rez += (last - k + 1) * ((n - k) / i + 1);

        if(last + 1 < i)
            rez += ((i - 1) - (last + 1) + 1) * ((n - (last + 1)) / i + 1);

       /* int  a =0 ;
        int b = 0;
        aps.clear();
        for(int j = k; j < i ; j ++)
        {
            int mx = (n - j) / i + 1;
            rez2 += mx;

            aps[mx] ++;
        }*/
       /* apx[(n - (last + 1)) / i + 1] = ((i - 1) - (last + 1) + 1);
        apx[(n - k ) / i + 1] = (last - k + 1);

        //cout << "ARE " << aps.size() << "\n";
        for(map <int, int> :: iterator it = aps.begin(); it != aps.end(); it ++)
        {
            //cout << it -> first << " " << it -> second << "\n";

            if(apx[it -> first] != it -> second)
            {
                cout << "eROAORORORO ";
                cout << k << " " << "++ " << last << "    +-+-+ "  << it -> first << " " << it -> second << " " << apx[it -> first] << "\n";

                return 0;
            }
        }*/
        //cout << "\n";

     //   cout << a << " " << b << "\n";


    }

    cout << rez - (k == 0) * n << "\n";
    //cout << rez2 << "\n";

    return 0;
}
