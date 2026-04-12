#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin,(obj).end()
#define SORT(list) sort(ALL((list)));
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector <string> s(n);
    REP(i,n)cin >> s[i];
    string answer;
    REP(i,n)sort(s[i].begin(),s[i].end());
    int count;
    int min = 51;
    REP(i,26){
        min = 51;
        REP(j,n){
            count = 0;
            REP(k,s[j].length()){
                if(s[j].at(k)=='a'+i)count++;
            }
            //cout << min << " " << count << endl;
            if(count<min){
                min = count;
            }
        }
        REP(j,min){
            //answer += std::string('a'+i);
            printf("%c",'a'+i);
        }
    }

    cout << endl;
    return 0;
}