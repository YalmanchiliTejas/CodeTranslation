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

int main(){
    //ifstream cin("inputAB55_1.txt");
    
    int N;
    int x,y;
    
    string str;
    vector<string> words;
    
    getline(cin, str);
    trim(str);
    N = atoi(str.c_str());
    
    x = 800 * N;
    y = 200 * (N / 15);

    cout << x-y << endl;
    
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
