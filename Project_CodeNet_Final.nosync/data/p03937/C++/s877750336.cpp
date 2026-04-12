#include<bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;

#define debugv(v) printf("L%d %s => ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;
#define debugm(m) printf("L%d %s is..\n",__LINE__,#m);for(auto v:m){for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) printf("L%d %s is => ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;
#define debugaa(m,w,h) printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[x][y]<<" ";}cout<<endl;}
#define ALL(v) (v).begin(),(v).end()
#define BIGINT 0x7FFFFFFF
#define E107 1000000007
void printbit(int u){if(u==0)cout<<0;else{int s=0,k=0;for(;0<u;u>>=1,k++)s=(s<<1)|(u&1);for(;0<k--;s>>=1)cout<<(s&1);}}

#define TIME chrono::system_clock::now()
#define MILLISEC(t) (chrono::duration_cast<chrono::milliseconds>(t).count())

template<typename T1,typename T2>
ostream& operator <<(ostream &o,const pair<T1,T2> p){o<<"("<<p.first<<":"<<p.second<<")";return o;}

int m,n;
int width,height;
string field[10];

int main(){
    int i,j,k,l;
    int x,y;
    
    cin >> height >> width;cin.ignore();
    
    for (i=0;i<height;i++){
        cin >> field[i];
    }
    
    int count = 0;
    for (y=0;y<height;y++){
        for (x=0;x<width;x++){
            count += field[y][x]=='#';
        }
    }
    if (count!=width+height-1){
        cout << "Impossible" << endl;
        return 0;
    }
    
    queue<vector<int>> q;
    q.push(vector<int>{0,0});
    while (!q.empty()){
        vector<int> &e =q.front();
        x = e[0];
        y = e[1];
        q.pop();
        
        if (x == width-1 && y == height-1){
            cout << "Possible" << endl;
            return 0;
        }
        if (x < width-1 && field[y][x]=='#'){
            q.push(vector<int>{x+1,y});
        }
        if (y < height-1 && field[y][x]=='#'){
            q.push(vector<int>{x,y+1});
        }
    }
    cout << "Impossible" << endl;

    return 0;
}