#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
using namespace std;
#define rep(i,m,n) for (int i = (int) (m); i < (int) (n); i++)
#define rep1(i,m,n) for (int i = (int) (m); i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
int main(void){
    string N;
    cin>>N;
    if(N.at(0)==N.at(1) && N.at(1)==N.at(2))cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
