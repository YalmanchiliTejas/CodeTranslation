#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
using namespace std;

struct Point{
    int x,y,z;
    Point(int x, int y, int z):x(x), y(y), z(z){}
    Point(){}
    Point &operator +=(const Point &a){ x+=a.x; y+=a.y; z+=a.z; return *this; }
    Point &operator -=(const Point &a){ x-=a.x; y-=a.y; z-=a.z; return *this; }
    Point operator +(const Point &a) const{ return Point(x+a.x, y+a.y, z+a.z); }
    Point operator -(const Point &a) const{ return Point(x-a.x, y-a.y, z-a.z); }
    Point operator -() { return Point(-x, -y, -z); }
    bool operator < (const Point &a) const{
        return (x!=a.x)? x<a.x: (y!=a.y)? y<a.y: z<a.z;
    }
    bool operator == (const Point &a) const{
        return x==a.x && y==a.y && z==a.z;
    }
};

template<typename T>
void pair_recsort(vector<pair<T, T> > &vec){
    for(pair<T, T> &e: vec){
        if(e.second < e.first){
            swap(e.first, e.second);
        }
    }
    sort(vec.begin(), vec.end());
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<vector<pair<Point, Point> > > key(2);
        for(int d=0; d<2; d++){
            int size;
            if(d == 0) size = n;
            else cin >> size;
            map<int, Point> itop;
            Point pos(0, 0, 0);
            for(int i=0; i<size; i++){
                string s;
                cin >> s;
                if('0' <= s[0] && s[0] <= '9'){
                    int idx = stoi(s);
                    if(itop.count(idx) == 0){
                        itop[idx] = pos;
                    }else{
                        pos = itop[idx];
                    }
                }else{
                    Point next = pos;
                    int sign = (s[0]=='+')? 1: -1;
                    if(s[1] == 'x') next.x += sign;
                    if(s[1] == 'y') next.y += sign;
                    if(s[1] == 'z') next.z += sign;
                    key[d].push_back(make_pair(pos, next));
                    pos = next;
                }
            }
            pair_recsort(key[d]);
        }
        
        bool same = false;
        for(int axisswap=0; axisswap<3; axisswap++){
            for(auto &p: key[0]){
                swap(p.first.x, p.first.y);
                swap(p.first.y, p.first.z);
                swap(p.second.x, p.second.y);
                swap(p.second.y, p.second.z);
            }
            for(int zturn=0; zturn<2; zturn++){
                for(auto &p: key[0]){
                    p.first.y = -p.first.y;
                    p.first.z = -p.first.z;
                    p.second.y = -p.second.y;
                    p.second.z = -p.second.z;
                }
                for(int zrotate=0; zrotate<4; zrotate++){
                    for(auto &p: key[0]){
                        Point newp;
                        newp.x = -p.first.y;
                        newp.y = p.first.x;
                        newp.z = p.first.z;
                        p.first = newp;
                        newp.x = -p.second.y;
                        newp.y = p.second.x;
                        newp.z = p.second.z;
                        p.second = newp;
                    }

                    pair_recsort(key[0]);
                    Point diff = key[1][0].first -key[0][0].first;
                    for(auto &p: key[0]){
                        p.first += diff;
                        p.second += diff;
                    }
                    if(key[0] == key[1]){
                        same = true;
                    }
                }
            }
        }

        if(same){
            cout << "SAME" << endl;
        }else{
            cout << "DIFFERENT" << endl;
        }
    }
    return 0;
}
