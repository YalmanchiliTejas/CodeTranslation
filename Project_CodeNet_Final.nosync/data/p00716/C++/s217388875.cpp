#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cctype>

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i,l,n) for(int (i)=(int)(l);(i)<(int)(n);(i)++)
#define d_arr(arr, h, w) rep(i,(h) ){ cout << "["; rep(j,(w) ) { cout << (arr)[i][j] << ", "; } cout << "]" << endl;}

typedef pair<int ,int> P;

class car
{
    int id;
    int num;
    public:
        car(int x, int y){ id=x; num=y; }
};

vector<double> ans;
int ini_m, years, n;
int style, fee;
double per;

double fukuri();
double tanri();
int main()
{
    int m;
    while ( cin >> m )
    {
        if( m == 0) { break; }
        //各データセットに対して
        rep(i,m) 
        {
            ans.clear();
            //cout << "--------------------------------------------------" << endl;
            cin >> ini_m >> years >> n;
            //各運用方法に対して
            rep(t,n) 
            {
                cin >> style >> per >> fee;
                double tmp;
                if     ( style == 0) { tmp = tanri();  ans.push_back(tmp);} //printf("tanri = %lf\n", tmp); }
                else if( style == 1) { tmp = fukuri(); ans.push_back(tmp);} //printf("fukuri = %lf\n", tmp); }
            }
            sort(ans.rbegin(), ans.rend() );
            //cout << ans[0] << endl;
            printf("%.0lf\n", ans[0] );
        }
    }
}

double tanri()
{
    double ret = ini_m;
    double interest = 0.0;
    double interest_sum = 0.0;
    rep(j,years)
    {
        interest = ret * per;
        interest_sum += floor(interest);
        ret -= fee;
    }
    return ret + interest_sum;
}

double fukuri()
{
    double ret = ini_m;
    double interest = 0.0;
    rep(j, years)
    {
        interest = ret * per;
        interest = floor(interest);
        ret += interest;
        ret -= fee;
    }
    return ret;
}