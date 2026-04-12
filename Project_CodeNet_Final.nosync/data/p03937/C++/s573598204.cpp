#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <boost/dynamic_bitset.hpp>
using namespace std;

pair<int,int> halfAdder(int a,int b)
{
    int s = a ^ b;
    int c = a & b;
    return make_pair(s,c);
}

pair<int,int> fullAdder(int a,int b,int c)
{
    pair<int,int> sum = halfAdder(a,b);
    pair<int,int> sum_ = halfAdder(sum.first,c);
    int s = sum_.first;
    c = sum.second | sum_.second;
    return make_pair(s,c);
}

template <typename Block, typename Allocator>
boost::dynamic_bitset<Block, Allocator>
operator+(const boost::dynamic_bitset<Block, Allocator>& x,
          const boost::dynamic_bitset<Block, Allocator>& y)
{
    vector<bool> t;
    int c = 0;
    for (int i = 0; i < x.size(); i++) {
        int a = x[i];
        int b = y[i];
        pair<int,int> r = fullAdder(a,b,c);

        t.push_back(r.first);
        c = r.second;
    }
    if(c) t.push_back(1);
    boost::dynamic_bitset< > s(t.size());
    for (int i = t.size()-1; i >= 0; i--) {
        if(t[i] == 1)s.set(i);
    }
    return s;
}

vector<boost::dynamic_bitset< >> bitEnum(int bit)
{
    vector<boost::dynamic_bitset< >> c;
    boost::dynamic_bitset< > a(bit);
    boost::dynamic_bitset< > b(bit);b.set(0);
    for (int i = 0; i < pow(2,bit); i++) {
        c.push_back(a);
        a = a + b;
    }
    return c;
}

vector<vector<char>> a;
int h,w;

vector<int> slv()
{
    vector<int> e;
    vector<boost::dynamic_bitset< >> b = bitEnum(h+w-1);
    for (auto x : b) {
        vector<vector<char>> c = vector<vector<char>>(h,vector<char>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                c[i][j] = a[i][j];
            }
        }
        int i = 0,j = 0;
        for(int k = 0;k < x.size(); k++){
            try{c.at(i).at(j) = '.';}catch(...){}
            if(x[k] == 1){
                //right
                try{if(c.at(i).at(j+1) != '#')break;}catch(...){}
                j++;
            }else{
                //down
                try{if(c.at(i+1).at(j) != '#')break;}catch(...){}
                i++;
            }
        }
        //cout << x << endl;
        int d = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(c[i][j] == '.')d++;
                //cout << c[i][j];
            }
            //cout << "" << endl;
        }
        //cout << "" << endl;
        if(d == h*w)e.push_back(0);
        else e.push_back(1);
    }
    return e;
}

int main(int argc, char const* argv[])
{
    cin>>h>>w;
    a = vector<vector<char>>(h,vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin>>a[i][j];
        }
    }

    vector<int> a = slv();
    for (auto x : a) {
        if(x == 0){cout << "Possible" << endl;return 0;}
    }
    cout << "Impossible" << endl;

    return 0;
}