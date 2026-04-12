#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()

typedef long long ll;

using namespace std;
//using namespace boost::multiprecision;


int main(){

    int n;
    string s;
    cin >> n;
    cin >> s;

    //1匹目と2匹目を決め打ちしてそのあと、3匹目以降をsに従って、
    //順に決めていったときに、n匹目の動物が矛盾しないかをみる。

    //1を羊、0を狼とする
    vector<int> animals(n);

    function<int(int, int, char)> get_animal = [=](int n0, int n1, char c1) -> int{

        if(n1){
            if(c1 == 'o'){
                return n0;
            }else{
                return 1 - n0;
            }
        }else{
            if(c1 == 'o'){
                return 1 - n0;
            }else{
                return n0;
            }
        }
    };

    bool able = false;

    rep(i,2){
        rep(j,2){
            animals[0] = i;
            animals[1] = j;
        
            for(int k = 1; k < n - 1; k++){
                animals[k + 1] = get_animal(animals[k - 1], animals[k], s[k]);
            }

            if(get_animal(animals[n - 2], animals[n - 1], s[n - 1]) == animals[0]){
                if(get_animal(animals[n - 1], animals[0], s[0]) == animals[1]){
                    able = true;
                    break;
                }
            }
        }

        if(able){
            break;
        }
    }

    if(able){
        rep(i,n){
            if(animals[i]){
                cout << "S";
            }else{
                cout << "W";
            }
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}