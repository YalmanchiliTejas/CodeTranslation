#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}



int main() {

    int N; // 点の数
    int M; // 辺の数 
    cin >> N >> M;
    
    long a[M]; // 辺の繋がり開始点
    long b[M]; // 辺の繋がり終了点


    vector<int> nums;

    //vector<int> a_vec;
    //vector<int> b_vec;

    for (int i = 0; i < M ; i++) {
        //cin >> a[i] >> b[i];
        cin >> a[i] >> b[i];

        //a_vec.push_back(a[i]);
        //b_vec.push_back(b[i]);

        //cout << "aaa:  " << a[i] << "  bbb: " << b[i] <<  endl;

        //nums.push_back(i+1);
    }

    for (int i = 0; i < N ; i++) {

        nums.push_back(i+1);
    }

    // 頂点 1を始点として、全ての頂点を1度だけ訪れるパスは何通りありますか。
    // 1. 1 スタート
    // 2. 一度通った点は、２度訪れない
    // 3. N 個

    int cnt = 0;
    //int path_cnt = 0;


    // vector順列総当たりループ
    do {
        //printVector(nums);

        int path_cnt = 0;

        // vector要素数分の処理
        for (int i = 1; i < N ; i++) {
            // 1　スタートのみ
            if (nums.at(0) != 1){
                continue;
            }

            int now = nums.at(i-1);
            int next = nums.at(i);
            //cout << "now:  " << now << "  next: " << next <<  endl;

            // 辺の定義分ループ
            bool route_flg = false;
            for (int j = 0; j < M ; j++) {

                //cout << "a:  " << a_vec.at(j) << "  b: " << b_vec.at(j) <<  endl;

                //[now-next]間の辺の存在チェック
                if ((now == a[j] && next == b[j]) || (now == b[j] && next == a[j])){
                //if ((now == a_vec.at(j) && next == b_vec.at(j)) || (now == b_vec.at(j) && next == a_vec.at(j))){
                    route_flg = true;
                    //break;
                }
            }
            if(route_flg){
                 path_cnt++;
            }
        }

        if(path_cnt == N -1){
            //cout << "cnt up " << endl;
            cnt++;
        }
        //printVector(nums);

    } while (next_permutation(nums.begin()+1, nums.end()));


    cout << cnt << endl;

}