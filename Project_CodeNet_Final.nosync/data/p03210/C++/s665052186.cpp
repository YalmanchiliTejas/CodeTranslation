#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <array>
#include <queue>
#include <list>
#include <sstream>

using namespace std;

const int INF = 100000000;
const int MAX_N = 100000;

/**
 * stringのvectorで二次元配列を読み込む
 */
vector< vector<char> > readVec(vector< vector<char> > vec, int height, int width) {
    for(int i=0; i<height; i++) {
        vector<char> insideVec;
        for(int j=0; j<width; j++) {
            char c;
            cin >> c;
            insideVec.push_back(c);
        }
        vec.push_back(insideVec);
    }
    return vec;
}

/**
 * 二次元vectorの初期化
 */
vector< vector<int> > initVec(vector< vector<int> > vec, int height, int width) {
    for(int i=0; i<height; i++){
        vector<int> newVec(width);
        for(int j=0; j<width; j++){
            newVec[j] = INF;
        }
        vec.push_back(newVec);
    }
    return vec;
}

/**
 * stringのvectorをprint
 */
void printVector(vector< vector<char> > &vec) {
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[0].size(); j++){
            cout << vec[i][j];
        }
        cout << endl;
    }
}

/**
 * intのvectorをprint
 */
void printIntVectorVector(vector< vector<int> > &vec) {
    for(int i=0; i<vec.size(); i++){
        cout << "[";
        for(int j=0; j<vec[0].size(); j++){
            cout << vec[i][j] << ",";
        }
        cout << "]" << endl;
    }
}

/**
 * intのvectorをprint
 */
void printIntVector(vector<int> &vec) {
    cout << "[";
    for(int j=0; j<vec.size(); j++){
        cout << vec[j] << ",";
    }
    cout << "]" << endl;
}

/**
 * フィボナッチ数列
 */
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

vector<string> split(const string &str, char sep)
{
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}

/**
 * 深さ優先探索
 */
class Dfs {
    public:
        int height, width, count;
        vector< vector<char> > vec;
        
        bool dfs(int x, int y) {
            if (vec[y][x] == 'g') {
                this->count++;
                return true;
            }

            if (vec[y][x] == '#') {
                return false;
            }

            int dy[] = {0, 1, 0, -1};
            int dx[] = {1, 0, -1, 0};

            if (this->count == 0 && (vec[y][x] == '.' || vec[y][x] == 's')) {
                vec[y][x] = '#';
                // printVector(vec);
                for(int i=0; i<4; i++) {
                    if(((y + dy[i]) < height) &&
                        ((y + dy[i]) >= 0) &&
                        ((x + dx[i]) < width) &&
                        ((x + dx[i]) >= 0)) {
                        
                        dfs(x + dx[i], y + dy[i]);
                    }
                }
            }

            if(this->count == 0) return false;
            else return true;
        }

        Dfs(int height, int width, int count, vector< vector<char> > vec) {
            this->vec = vec;
            this->height = height;
            this->width = width;
            this->count = count;
        }
};

/**
 * 幅優先探索
 */
class Bfs {
    public:
        typedef pair<int, int> P;
        vector< vector<char> > inputVec;
        vector< vector<int> > countVec;

        int startX, startY;
        int goalX, goalY;
        int height, width;

        int bfs() {
            queue<P> que;
            que.push(P(startX, startY));
            this->countVec[startY][startX] = 0;

            while(que.size() != 0) {
                P point = que.front();
                que.pop();

                int nowX = point.first;
                int nowY = point.second;

                if (nowX == goalX && nowY == goalY) {
                    break;
                }

                int dx[] = {0, 1, 0, -1};
                int dy[] = {1, 0, -1, 0};

                for(int i=0; i<4; i++){
                    int newX = nowX + dx[i];
                    int newY = nowY + dy[i];

                    if(newX >= 0 && 
                        newX < this->width &&
                        newY >= 0 &&
                        newY < this->height &&
                        inputVec[newY][newX] != '#' &&
                        countVec[newY][newX] == INF
                    ) {
                        P newPoint = P(newX, newY);
                        que.push(newPoint);
                        
                        // cout << inputVec[newY][newX] << endl;
                        // cout << newX << newY << endl;

                        this->countVec[newY][newX] = this->countVec[nowY][nowX] + 1;
                    }
                }
            }
            return countVec[goalY][goalX];
        }
        
        Bfs(int startX, int startY, int goalX, int goalY, int height, int width, vector< vector<char> > inputVec, vector< vector<int> > countVec) {
            this->startX = startX;
            this->startY = startY;
            this->goalX = goalX;
            this->goalY = goalY;
            this->height = height;
            this->width = width;
            this->inputVec = inputVec;
            this->countVec = countVec;
        }
};

/**
 * コインの貪欲法。
 */
class Donyoku {
    public:
        int solve() {
            int pay, back;
            array<int, 6> money = {500, 100, 50, 10, 5, 1};
            cin >> pay;
            back = 1000 - pay;

            int num = 0;

            for(int i=0; i<6; i++){
                int eachNum = back / money[i];
                back = back % money[i];

                num += eachNum;
            }

            cout << num << endl;

            return 0;
        }
};

/**
 * 区間スケジューリング
 * https://atcoder.jp/contests/kupc2015/tasks/kupc2015_a
 */
class Schedule {
    public:
        int solve() {
            int num;
            cin >> num;

            for (int i=0; i<num; i++){
                string input;
                cin >> input;

                int ans = count(input);
                cout << ans << endl;
            }

            return 0;
        }

        int count(string s) {
            int count = 0;
            int i=0;

            if (s.length() <5) return 0;

            while(i <= (s.length() -5)) {
                string kukan = s.substr(i, 5);

                if(kukan == "tokyo" || kukan == "kyoto") {
                    count++;
                    i += 5;
                } else {
                    i++;
                }
            }

            return count;
        }
};

/**
 * 辞書順
 * https://abc076.contest.atcoder.jp/tasks/abc076_c
 */
class ZisyoJun {
    public:
        int solve() {
            string sdash, t;
            cin >> sdash >> t;

            string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
            string no = "UNRESTORABLE";

            if(sdash.length() < t.length()) {
                cout << no << endl;
                return 0;
            }

            for(int i=0; i<=sdash.length()-t.length(); i++){
                string newsdash = sdash;
                if(newsdash.at(i) == '?' or newsdash.at(i) == t.at(0)) {
                    string sdashSubstr = newsdash.substr(i, t.length());
                    if(isSame(sdashSubstr, t)) {
                        // iからi+t.length()までをtの文字列に置き換える。
                        for(int j=i; j<i+t.length(); j++){
                            newsdash.at(j) = t.at(j-i);
                        }
                        // 残りの?を全てaに置き換える
                        for(int k=0; k<newsdash.length(); k++){
                            if(newsdash.at(k) == '?') newsdash.at(k) = 'a';
                        }
                        if(newsdash < ans) ans = newsdash;
                    }
                }
            }

            if(ans == "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz") {
                ans = no;
            }

            cout << ans << endl;

            return 0;
        }

        bool isSame(string s, string t) {
            bool issame = true;;
            if(s == t) return true;
            for(int i=0; i<s.length(); i++){
                if(s.at(i) == t.at(i) or s.at(i) == '?') {
                    continue;
                } else {
                    issame = false;
                    break;
                }
            }
            return issame;
        }
};

/**
 * ナップサックdp
 */
class NapSack {
    public:
        int n, W;
        int weight[110], value[110];

        // DPテーブル
        int dp[110][10010];

        int main() {
            cin >> n >> W;
            for (int i = 0; i < n; ++i) cin >> value[i] >> weight[i];

            // DP初期条件: dp[0][w] = 0
            for (int w = 0; w <= W; ++w) dp[0][w] = 0;

            // DPループ
            for (int i = 0; i < n; ++i) {
                for (int w = 0; w <= W; ++w) {
                    if (w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
                    else dp[i+1][w] = dp[i][w];
                }
            }

            cout << dp[n][W] << endl;

            return 0;
        }
};

/**
 * 部分和問題
 */
// class Bubunwa {
//     public:
//         bool dp[MAX_N][MAX_N];
//         int numArray[MAX_N];

//         int solve() {
//             int num;
//             cin >> num;
            
//             for(int i=0; i<num; i++) {
//                 int input;
//                 cin >> input;
//                 numArray[i] = input;
//             }

//             for(int i=0; i<num; i++){
//                 int e = numArray[i];
//                 dp[e]
//             }
//             return 0;
//         }
// };

int main() {
    // ZisyoJun zisyojun;
    // zisyojun.solve();
    string s, ans;
    cin >> s;

    if(s == "5" or s == "3" or s == "7") {
        ans = "YES"; 
    } else {
        ans = "NO";
    }

    cout << ans << endl;
}

/*
文字列の長さ str.length()

#list は挿入と削除が頻繁に行われる場合
・要素を先頭に追加: push_front()
・要素を末尾に追加: push_back();

#vector は検索が速い
・vectorの長さ: vector.size()
初期化
vector<int> vec(3);
vec.at(1);
・要素を先頭に追加: push_front()
・要素を末尾に追加: push_back();

charからintに変換
atoi(num.c_str())

stringからintに変換
stoi(str)

intからstringに変換
to_string(num)

stringを分割
split("a:b:c", ":")

vectorの昇順ソート
sort(data.begin(),data.end());
vectorの降順ソート
sort(data.begin(),data.end(),std::greater<int>());

vectorの任意の位置の値の削除
takoVec.erase(takoVec.begin() + index-1);

vectorの先頭に追加
takoVec.insert(takoVec.begin(), input);

pair<int, int> numArray[MAX_N];
numArray[i].first = ~~;
numArray[i].second = ~~;
*/