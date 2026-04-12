#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

vector<int> line_to_array(istream& is, const int cnt, const char sep);
vector<string> split(const string &str, const char sep);
string trim(const string& str, const char* trimCharacterList  = " \t\v\r\n");
bool chk_rcsv(int j, int k, char** t, bool** chk_t, string str, int pos);

int N;
bool *say;
bool *isS;

bool chk();
bool chk_rest(int l, int r);

int main(){
    //ifstream cin("inputAB55_4.txt");

    string str;
    vector<string> words;
    
    getline(cin, str);
    trim(str);
    N = atoi(str.c_str());
    say = new bool[N+1];
    isS = new bool[N+1];
    
    getline(cin, str);
    for(int i=0; i<N; i++){
        if(str[i] == 'o'){
            say[i] = true;
        }else{
            say[i] = false;
        }
    }
    say[N] = say[0];

    bool success = chk();
    
    if(success){
        for(int i=0; i<N; i++){
            if(isS[i]){
                cout << "S";
            }else{
                cout << "W";
            }
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    
    delete[] say;
    delete[] isS;
    return 0;
}

bool chk(){
    if(say[0]){
        //0番目が羊、両隣が羊
        isS[0] = true; isS[N] = true;
        isS[N-1] = true; isS[1] = true;
        if(chk_rest(N-1,1)) return true;
        
        //0番目が羊、両隣が狼
        isS[0] = true; isS[N] = true;
        isS[N-1] = false; isS[1] = false;
        if(chk_rest(N-1,1)) return true;
        
        //0番目が狼、両隣が羊、狼
        isS[0] = false; isS[N] = false;
        isS[N-1] = true; isS[1] = false;
        if(chk_rest(N-1,1)) return true;
        
        //0番目が狼、両隣が狼、羊
        isS[0] = false; isS[N] = false;
        isS[N-1] = false; isS[1] = true;
        if(chk_rest(N-1,1)) return true;
    }else{
        //0番目が羊、両隣が羊、狼
        isS[0] = true; isS[N] = true;
        isS[N-1] = true; isS[1] = false;
        if(chk_rest(N-1,1)) return true;
        
        //0番目が羊、両隣が狼、羊
        isS[0] = true; isS[N] = true;
        isS[N-1] = false; isS[1] = true;
        if(chk_rest(N-1,1)) return true;
        
        //0番目が狼、両隣が羊
        isS[0] = false; isS[N] = false;
        isS[N-1] = true; isS[1] = true;
        if(chk_rest(N-1,1)) return true;
        
        //0番目が狼、両隣が狼
        isS[0] = false; isS[N] = false;
        isS[N-1] = false; isS[1] = false;
        if(chk_rest(N-1,1)) return true;
    }
    return false;
}

//3匹が決まっていれば、両隣を次々に決められる
//ただし、終端で整合をチェックする
bool chk_rest(int l, int r){
    int nl_isS,nr_isS;
    
    if( isS[l] == say[l] ){
        nl_isS = isS[l+1];
    }else{
        nl_isS = !isS[l+1];
    }
    
    if( isS[r] == say[r] ){
        nr_isS = isS[r-1];
    }else{
        nr_isS = !isS[r-1];
    }
    
    //終端整合チェック
    if(l-r == 0){
        if(nl_isS == isS[r-1] && nr_isS == isS[l+1]){
            return true;
        }
        return false;
    }
    if(l-r == 1){
        if(nl_isS == isS[r] && nr_isS == isS[l]){
            return true;
        }
        return false;
    }
    if(l-r == 2){
        if(nl_isS != nr_isS){
            return false;
        }
    }
    //終端でなければ次の動物を決める
    isS[l-1] = nl_isS;
    isS[r+1] = nr_isS;
    return chk_rest(l-1, r+1);
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
