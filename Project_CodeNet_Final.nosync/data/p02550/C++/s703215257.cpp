#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <functional>
#include <set>
#include <map>
#include <bitset>
#include <list>

using namespace std;


#define INF pow(10, 9)
// typedef priority_queue<tuple<int,int,int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > PQ;

typedef long long int ll;




int main(void)
{

    ll N, X, M;
    cin >> N >> X >> M;

    const int Max = pow(10, 5);
    int count[Max] = {0};
    vector<int> As(Max+3, 0); //As[0]は使わない

    ll A_new = X;
    int index = 1;

    while(count[A_new]==0 )
    {
        count[A_new] ++;
        As[index++] = A_new;
        A_new = A_new * A_new %M;
        if(A_new <0) A_new += M;
        // cout << index-1 << " " << As[index-1] << endl;
    }

    int A_looped = A_new;



    if(N < index)
    {
        ll Sum = 0;
        for(int i=1; i<=N; i++)
        {
            Sum += As[i];
        }
        cout << Sum << endl;
    }
    else
    {
        ll Sum_bef =0;
        ll Sum_loop = 0;
        int index_loop_start=0;
        for(int i=1; i<=index; i++)
        {
            if(As[i] == A_looped)
            {
                index_loop_start = i;
                break;
            }
            else
            {
                Sum_bef += As[i];
            }
        }

        int N_loop_index = index-index_loop_start;
        for(int i=0; i<N_loop_index; i++)
        {
            Sum_loop += As[index_loop_start+i];
        }

        ll times_loop = (N-index_loop_start+1)/N_loop_index;
        ll residual = (N-index_loop_start+1)- times_loop * N_loop_index;

        // cout << index << "! " << index_loop_start << ", " << N_loop_index << "// " << times_loop << "::: " << residual << endl;
        // cout << Sum_bef << " b " << Sum_loop << endl;

        for(int i=0; i<residual; i++)
        {
            Sum_bef += As[index_loop_start+i];
        }
        ll Sum = Sum_bef+Sum_loop * times_loop;
        cout << Sum << endl;
    }




    return 0;
}
