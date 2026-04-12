#include <bits/stdc++.h>
#include <unistd.h>
#include <random>
using namespace std;

typedef long long int LL;
typedef long long int LLint;
typedef pair<int,int> intpair;
typedef pair<bool,bool> boolpair;
typedef pair<string,string> strpair;
typedef pair<LL,LL> LLpair;
typedef pair<double,double> doublepair;
typedef pair<float,float> floatpair;
typedef vector<int> intvector;
typedef vector<bool> boolvector;
typedef vector<string> strvector;
typedef vector<LL> LLvector;
typedef vector<double> doublevector;
typedef vector<float> floatvector;
#define wait(sec) usleep((sec) * 1000000)
#define ED return 0;
#define TEST cout << "OK" << endl;
#define UP(a,b) ((a+(b-1))/b)
#define SORT(vec) sort(vec.begin(),vec.end());
#define DOUBLECHANGE(count) cout << setprecision(count);
#define REV(vec) reverse(vec.begin(),vec.end());
#define ipow(x,y) LL(pow(x,y))
#define INF 999999999
const long long mod = 1000000007;

int main(){
//    random_device rnd;
//    mt19937 mt(rnd());
    cin.tie(0);
    ios::sync_with_stdio(false);
    char c;
    cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        cout << "vowel" << endl;
    }
    else{
        cout << "consonant" << endl;
    }
}
