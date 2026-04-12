#include "bits/stdc++.h"
using namespace std;


/* macro */
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i = a; i > b; i--)
#define int long long
#define exist(s,e) ((s).find(e)!=(s).end())
#define all(v) (v).begin(), (v).end()
#define each(s,itr) for(auto (itr) = s.begin(); (itr) != s.end(); (itr)++)
#define sum(v) accumulate(all(v), (0LL))


/* alias */
template<class T> using vec = vector<T>;
typedef vector<int> vi;
typedef pair<int, int> pi;


/* constant */
const int inf = 100100100100100100;
const int mod = 1e9;
int dx[8]={1,0,-1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,-1,-1,1,1};


/* io_method */
int input(){int tmp;cin >> tmp;return tmp;}
string raw_input(){string tmp;cin >> tmp;return tmp;}
string readline(){string s;getline(cin, s);return s;}
template<class T> void printx(T n){cout << n;}
template<class T, class U> void printx(pair<T, U> p){cout << "(" << p.first << "," << p.second << ")";}
template<class T> void printx(vector<T> v){cout << "{";rep(i,0,v.size()){printx(v[i]);if(i != v.size()-1)printx(",");}cout << "}";}
template<class T> void print(T n){printx(n);cout << endl;}
template<class T> void print(set<T> s){cout << "{";each(s, e){if(e != s.begin()) printx(",");printx(*e);}cout << "}" << endl;}
template<class T, class U> void print(map<T, U> mp){cout << "{";each(mp, e){cout << "(" << e -> first << "," << e -> second << ")";}cout << "}" << endl;}


/* general_method */
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
vector<int> cs(vector<int> arr){vector<int> tmp;if(arr.size() == 0) return tmp;tmp.push_back(arr[0]);rep(i,1,arr.size()){tmp.push_back(tmp.back() + arr[i]);}return tmp;}



/* main */



signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);



 
    int n = input();

    vi arr; rep(i,0,n) arr.push_back(input());
    sort(all(arr));

    if(n == 2){
        print(abs(arr[0] - arr[1]));
        return 0;
    }

    deque<int> q;

    q.push_back(arr[0]);
    q.push_back(arr.back());

    int l = 1, r = n - 2;

    while(!(l > r)){

        int ltob = abs(arr[l] - q.back());
        int ltof = abs(arr[l] - q.front());
        int rtob = abs(arr[r] - q.back());
        int rtof = abs(arr[r] - q.front());

        if(ltob >= ltof && ltob >= rtob && ltob >= rtof){
            q.push_back(arr[l]);

            l++;
        }else if(ltof >= ltob && ltof >= rtob && ltof >= rtof){
            q.push_front(arr[l]);

            l++;
        }else if(rtob >= ltob && rtob >= ltof && rtob >= rtof){
            q.push_back(arr[r]);
            r--;
        }else if(rtof >= ltob && rtof >= ltof && rtof >= rtob){
            q.push_front(arr[r]);

            r--;
        }

    }
    vi tmp;
    each(q, itr){
        tmp.push_back(*itr);
    }

    int ans = 0;
    rep(i,1,n){
        ans += abs(tmp[i - 1] - tmp[i]);
    }

    print(ans);
    


    

    
   
    













}






    










    




    








