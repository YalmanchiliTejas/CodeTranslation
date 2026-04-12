//おまじない
#include <iostream>
#include<iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない
const int maxn = 100000;
ll mod = INF;
int N;
string s;
string c;

bool jud(int N,char first,char last){
    c[0]=first;
    c[N-1]=last;
    rep(i,N){
        //cout <<"jud"<< i<<endl;
        int preidx = (N-1+i)%N;
        int next = (i+1)%N;
        if(c[i]=='W'&&s[i]=='o'){  //狼かつ両側違う
            if(c[preidx]=='W')c[next]='S';
            else c[next]='W';
        }else if(c[i]=='W'&&s[i]=='x'){//狼かつ両方同じ
            if(c[preidx]=='W')c[next]='W';
            else c[next]='S';
        }else if(c[i]=='S'&&s[i]=='o'){//羊かつ両方同じ
            if(c[preidx]=='W')c[next]='W';
            else c[next]='S';
        }else if(c[i]=='S'&&s[i]=='x'){//羊かつ両方違う
            if(c[preidx]=='W')c[next]='S';
            else c[next]='W';
        }
    }
    
    return last == c[N-1]&&c[0]==first;
}

int main(){
    cin >> N;
    cin >> s;
    c=s;
    //s[0]を狼、s[N-1]を狼とする
    //cout << 1<<endl;
    c[0]='W';
    c[N-1]='W';
    char last = 'W';
    if(jud(N,'W','W')){
        cout << c;
        cout <<endl;
        return 0;
    }
    //s[0]を狼、s[N-1]を羊とする
    //cout << 2<<endl;
    c[0]='W';
    c[N-1]='S';
    last = 'S';
    if(jud(N,'W','S')){
         cout << c;
         cout <<endl;
        return 0;
    }
    //s[0]を羊、s[N-1]を狼とする
    //cout << 3<<endl;
    c[0]='S';
    c[N-1]='W';
    last = 'W';
    if(jud(N,'S','W')){
         cout << c;
         cout <<endl;
        return 0;
    }
    
    //s[0]を羊、s[N-1]を羊とする
    //cout << 4<<endl;
    c[0]='S';
    c[N-1]='S';
    last = 'S';
    if(jud(N,'S','S')){
         cout << c;
         cout <<endl;
        return 0;
    }
    
    cout << -1<<endl;
    return 0;
}
    

