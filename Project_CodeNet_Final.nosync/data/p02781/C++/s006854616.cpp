#include <bits/stdc++.h>

#define MAX_N 109

using namespace std;

typedef long long lint;

string s;
int k;

int cif;

lint rez;
lint getComb(int n, int k)
{
    if(k == 0 || k == n)
        return 1;

    if(k > n)
        return 0;

    //cout << " INTREU COMB " << n << " " << k << "\n";

    lint rez = 1;
    for(lint i = n; i >= n - k + 1; i --)
    {
        rez = rez * i;
    }

    for(int i = 1; i <= k; i ++)
        rez /= i;

    //cout << " IES COMB " << rez << "\n";

    return rez;
}

lint p[5];

int main()
{
    cin >> s;
    cin >> k;
//cout << "GATA CITIRea\n";

    cif = s.size();

    p[0] = 1;
    for(int i = 1; i <= 3; i ++)
        p[i] = p[i - 1] * 9;

    for(int i = k; i < cif; i ++)
    {
        rez += getComb(i - 1, k - 1) * p[k];
    }

   // cout << rez << " + " << getComb(cif - 1, k) * p[k] << " < N\n";


/*
    if(s[0] - '0' > 1)
    {
        rez += (s[0] - '0' - 1) * getComb(cif - 1, k - 1) * p[k - 1];
    }*/

    //cout << " DUPA 1 cif\n" << rez << "\n";

    int cate = 0;
    rez = 0;
    for(int i = 0; i < cif; i ++)
    {


        if(s[i] - '0' != 0)
            cate ++;

        if(cate <= k && s[i] != '0' )
        {
            rez += (s[i] - '0' - 1) * getComb(cif - (i + 1), k - cate) * p[k - cate];
            rez += getComb(cif - (i + 1), k - cate + 1) * p[k - cate + 1];
          //  cout << " DUPA " << i << " EGALE " << rez << "\n";
        }
    }

    if(cate >= k)
        rez ++;

    cout << rez << "\n";

    return 0;
}
