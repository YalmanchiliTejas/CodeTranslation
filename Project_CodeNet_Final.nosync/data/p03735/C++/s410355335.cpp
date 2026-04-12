#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PB push_back
using namespace std;
typedef pair<int, int> P1;
typedef pair<int, pair<int, int> > P2;
static const int INF = 1ll<<60;
static const int dx[] = { 1, -1, 0, 0, };
static const int dy[] = { 0, 0, 1, -1 };
static const int mod = 1000000007;
static const int MAX_N = 200000;

int dat_max[600000];
int dat_min[600000];

class Segment_MAX{
    public :
        int n;
        void init(int n_){
            n=1;
            while(n<n_)n*=2;
            for(int i=0;i<n*2-1;++i)dat_max[i]=-INT_MAX;
        }

        void update(int k,int a){
            k+=n-1;
            dat_max[k]=a;
            while(k>0){
                k=(k-1)/2;
                dat_max[k]=max(dat_max[k*2+1],dat_max[k*2+2]);
            }
        }

        int query(int a,int b,int k,int l,int r){
            if(a<=l&&r<=b)return dat_max[k];
            if(r<=a||b<=l)return -INT_MAX;
            else {
                int vl=query(a,b,k*2+1,l,(l+r)/2);
                int vr=query(a,b,k*2+2,(l+r)/2,r);
                return max(vl,vr);
            }
        }
};

class Segment_MIN{
    public :
        int n;
        void init(int n_){
            n=1;
            while(n<n_)n*=2;
            for(int i=0;i<n*2-1;++i)dat_min[i]=INT_MAX;
        }

        void update(int k,int a){
            k+=n-1;
            dat_min[k]=a;
            while(k>0){
                k=(k-1)/2;
                dat_min[k]=min(dat_min[k*2+1],dat_min[k*2+2]);
            }
        }

        int query(int a,int b,int k,int l,int r){
            if(a<=l&&r<=b)return dat_min[k];
            if(r<=a||b<=l)return INT_MAX;
            else {
                int vl=query(a,b,k*2+1,l,(l+r)/2);
                int vr=query(a,b,k*2+2,(l+r)/2,r);
                return min(vl,vr);
            }
        }
};

int N;
vector<P1> ball;

//R_min = MIN , B_max = MAX の場合
int cal_1(){

    vector<int> R,B;
    for(auto v : ball){
        R.PB(min(v.first,v.second));
        B.PB(max(v.first,v.second));
    }
    sort(R.begin(),R.end());
    sort(B.begin(),B.end());
    return (R[N-1]-R[0])*(B[N-1]-B[0]);
}

//R_min = MIN , R_max = MAX の場合
int cal_2(){
    vector<P1> B;
    int MAX_R=-INF,MIN_R=INF;
    for(int i=0;i<N;++i){
        MAX_R = max(MAX_R,max(ball[i].first,ball[i].second));
        MIN_R = min(MIN_R,min(ball[i].first,ball[i].second));
    }
    Segment_MAX MAX;
    Segment_MIN MIN;
    MAX.init(MAX_N);
    MIN.init(MAX_N);
    for(int i=0;i<ball.size();++i){
        auto v = ball[i];
        MIN.update(i,v.second);
        MAX.update(i,v.second);
        B.PB(P1(v.second,i));
    }
    sort(B.begin(),B.end());
    int res = INF;
    for(int i=0;i<N;++i){
        int it = B[i].second;
        int x = ball[it].first,y=ball[it].second;
        MAX.update(it,x);
        MIN.update(it,x);
        int MAX_B,MIN_B;
        MAX_B = MAX.query(0,N,0,0,MAX.n);
        MIN_B = MIN.query(0,N,0,0,MIN.n);
        res = min(res,MAX_B-MIN_B);
    }
    return (MAX_R-MIN_R)*res;
}


signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        int x,y;
        cin>>x>>y;
        if(x<y)swap(x,y);
        ball.PB(P1(x,y));
    }
    cout<<min(cal_1(),cal_2())<<endl;
}

