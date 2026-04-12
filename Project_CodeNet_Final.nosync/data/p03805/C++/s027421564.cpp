#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
typedef long long ll;

vector<int> line_to_array(istream& is, const int cnt, const char sep);
vector<string> split(const string &str, const char sep);
string trim(const string& str, const char* trimCharacterList  = " \t\v\r\n");
bool chk_rcsv(int j, int k, char** t, bool** chk_t, string str, int pos);

int N,M;
bool visit[9];
bool path[9][9];

int p_cnt = 0;
int v_cnt = 0;

int traverse(int pos){
    int rtn = 0;
    //未訪問の時
    if(!visit[pos]){
        //現在位置を訪問済とする
        visit[pos] = true;
        v_cnt++;
        
        //すべて訪問済みなので戻り値1を設定する
        if(v_cnt == N){
            rtn = 1;
        }
        //まだ訪問していない場所があるので再帰的に調べる
        else{
            FOR(i, 1, 8){
                if(path[pos][i]){
                    rtn += traverse(i);
                }
            }
        }
        
        //現在位置を訪問未済とする
        v_cnt--;
        visit[pos] = false;
    }
    return rtn;
}

int solve(){
    return traverse(1);
}


int main(){
    //ifstream cin("inputAB54_C.txt");
    REP(i, 9){
        REP(j, 9){
            path[i][j] = false;
        }
        visit[i] = false;
    }
    cin >> N >> M;
    
    REP(i, M){
        int a,b;
        cin >> a >> b;
        path[a][b] = true;
        path[b][a] = true;
    }
    
    int output = solve();
    cout << output << endl;
    
    return 0;
}

vector<int> line_to_array(istream& is, const int cnt, const char sep){
    vector<int> v;
    string str;
    getline(is, str);
    vector<string> words = split(str, sep);
    for (int i=0; i < cnt; i++) {
        v.push_back( atoi(words[i].c_str()) );
    }
    return v;
}

vector<string> split(const string &str, const char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss, buffer, sep) ){
        v.push_back(buffer);
    }
    return v;
}

string trim(const string& str, const char* trimCharacterList)
{
    string result;
    string::size_type left = str.find_first_not_of(trimCharacterList);
    
    if (left != string::npos)
    {
        string::size_type right = str.find_last_not_of(trimCharacterList);
        result = str.substr(left, right - left + 1);
    }
    return result;
}
