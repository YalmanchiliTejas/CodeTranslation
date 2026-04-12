#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

class Path{
    public:
        int a, b;
};

vector<Path> p;
int n, m;

int count_ans(int ma, int start);

int main(){
    cin >> n >> m;
    p.resize(m);
    repi(i, p){
        *i = Path();
        cin >> (*i).a >> (*i).b;
    }
    cout << count_ans(1, 1) << endl;
    return 0;
}

int count_ans(int ma, int start){
    if(ma == (1 << n) - 1){
        return 1;
    }
    int res = 0;
    repi(i, p){
        if((*i).a == start && ((1 << ((*i).b - 1)) & ma) == 0){
            res += count_ans((1 << ((*i).b - 1)) | ma, (*i).b);
        }else if((*i).b == start && (1 << ((*i).a - 1) & ma) == 0){
            res += count_ans((1 << ((*i).a - 1)) | ma, (*i).a);
        }
    }
    return res;
}
