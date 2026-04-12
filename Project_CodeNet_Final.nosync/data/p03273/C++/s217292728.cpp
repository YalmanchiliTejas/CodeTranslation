#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;


int inputValue(){
    int a;
    cin >> a;
    return a;
};

void inputArray(int * p, int a){
    rep(i, a){
        cin >> p[i];
    }
};

void inputVector(vector<int> * p, int a){
    rep(i, a){
        int input;
        cin >> input;
        p -> push_back(input);
    }
}

template <typename T>
void output(T a, int precision) {
    if(precision > 0){
        cout << setprecision(precision)  << a << "\n";
    }
    else{
        cout << a << "\n";
    }
}
void check(long long a,long long b,long long c,long long d){
    long long same=a;
    a = a-b;
    while(same != a && a >= 0){
        cout << a << endl ;
        if(a <= c){
            a += d;
            if(a == same){
                cout << "Yes" << endl;
                return;
            }
        }
        a = a-b ;
    }

    if(a<0)
        cout << "No" << endl;
    return;
}


int main(int argc, const char * argv[]) {
    
    // source code
    int H,W;
    cin >> H;
    cin >> W;
    char a[H][W];
    rep(i,H){
        rep(j,W)
            cin >> a[i][j];
    }

int checki[H];
int checkj[W];

    rep(i,H){
        checki[i]=0;
        if(a[i][0] == '.'){
            rep(j,W){
                if(a[i][j] == '#')
                    checki[i]=1;
            }
        }else{
            checki[i] = 1;
        }
    }



    rep(j,W){
        checkj[j]=0;
        if(a[0][j] == '.'){
            rep(i,H){
                if(a[i][j] == '#')
                    checkj[j]=1;
            }
        }else{
            checkj[j]=1;
        }
    }


    rep(i,H){
        rep(j,W){
            if(checki[i]==1 && checkj[j]==1){
                cout << a[i][j];
            }
        }
        if(checki[i]==1)
            cout << endl;
    }




}