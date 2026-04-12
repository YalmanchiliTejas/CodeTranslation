#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <set>
using namespace std;

//関数getinputdata宣言
vector<vector<string>> getinputdata();
vector<vector<int>> getinputdata2();
vector<vector<double>> getinputdata3();

//奇数をカウント

bool rightcount(int i) {
    return (i >= 0);
}

void arc071_a(vector<vector<string>> v) {

    int n = atoi(v[0][0].c_str());

    map<string, int>h;

    string stemp = v[1][0];
    for (int j = 0; j < stemp.size(); j++) {

        h[stemp.substr(j, 1)] += 1;
    }

    for (int i = 2; i < 1 + n; i++) {
        string s = v[i][0];

        map<string, int>htemp;

        for (int j = 0; j < s.size(); j++) {

            htemp[s.substr(j, 1)] += 1;
        }

        for (auto x : h) {

            if (x.second > htemp[x.first]) {
                h[x.first] = htemp[x.first];
            }

        }

    }

    string result="";
    for (auto x : h) {

        if (x.second > 0) {
            int cnt=x.second;
            const char *c = x.first.c_str();
            
            result += string(cnt,*c);
        }
    }

    cout << result << endl;


}

int main() {

    vector<vector < string>> vec_arr_result;
    //    vector<vector<int>> vec_arr_result;
    vec_arr_result = getinputdata();

    arc071_a(vec_arr_result);

    return 0;
}

//関数getinputdata実装

vector<vector<double>> getinputdata3() {

    string str;
    string ret;
    stringstream ss;
    vector<string> v1;
    vector<vector<double>> vec_arr;

    //標準入力から入力がある間ループ処理でvector配列にデータ格納
    while (getline(cin, str)) {

        v1.push_back(str);

    }

    //stringstreamを利用してvector配列v1をスペースで分解処理
    for (string s : v1) {

        vector<double> array_data;
        ss << s;

        while (!ss.eof()) {

            ss >> ret;

            array_data.push_back(atof(ret.c_str()));
        }

        //vector配列に追加
        vec_arr.push_back(array_data);

        //バッファクリア
        ss.str("");
        //ストリームクリア
        ss.clear(stringstream::goodbit);

    }

    return vec_arr;
}

//関数getinputdata実装

vector<vector<int>> getinputdata2() {

    string str;
    string ret;
    stringstream ss;
    vector<string> v1;
    vector<vector<int>> vec_arr;

    //標準入力から入力がある間ループ処理でvector配列にデータ格納
    while (getline(cin, str)) {

        v1.push_back(str);

    }

    //stringstreamを利用してvector配列v1をスペースで分解処理
    for (string s : v1) {

        vector<int> array_data;
        ss << s;

        while (!ss.eof()) {

            ss >> ret;

            array_data.push_back(atoi(ret.c_str()));
        }

        //vector配列に追加
        vec_arr.push_back(array_data);

        //バッファクリア
        ss.str("");
        //ストリームクリア
        ss.clear(stringstream::goodbit);

    }

    return vec_arr;


}

//関数getinputdata実装

vector<vector < string >> getinputdata() {

    string str;
    string ret;
    stringstream ss;
    vector<string> v1;
    vector<vector < string>> vec_arr;

    //標準入力から入力がある間ループ処理でvector配列にデータ格納
    while (getline(cin, str)) {

        v1.push_back(str);

    }

    //stringstreamを利用してvector配列v1をスペースで分解処理
    for (string s : v1) {

        vector<string> array_data;
        ss << s;

        while (!ss.eof()) {

            ss >> ret;

            array_data.push_back(ret);
        }

        //vector配列に追加
        vec_arr.push_back(array_data);

        //バッファクリア
        ss.str("");
        //ストリームクリア
        ss.clear(stringstream::goodbit);

    }

    return vec_arr;

}
