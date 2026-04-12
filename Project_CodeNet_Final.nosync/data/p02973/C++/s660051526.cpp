#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr
#define INT_MAX_HALF (INT_MAX / 2)

typedef long long ll;

using namespace std;
//using namespace boost::multiprec

int main(){

    int n;
    cin >> n;

    vector<int> a;

    rep(i,n){
        int tmp;
        cin >> tmp;
        a.pback(tmp);
    }

    deque<int> each_color_min;

    each_color_min.pback(a[0]);

    for(int i = 1; i < n; i++){

        if(a[i] <= each_color_min[0]){
            each_color_min.push_front(a[i]);
        }else{
            auto itr = lower_bound(ALL(each_color_min), a[i]);
            if(itr == each_color_min.begin()){
                assert(false);
            }else{
                itr--;
                int idx = itr - each_color_min.begin();

                each_color_min[idx] = a[i];
            }
        }
    }

    cout << each_color_min.size() << endl;

    
    return 0;
}