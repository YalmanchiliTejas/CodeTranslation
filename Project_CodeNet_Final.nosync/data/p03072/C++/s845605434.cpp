#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i=0;i<N;i++)cin >> H.at(i);

    // 端の旅館からは必ず海が見れる
    int num_viewable = 1;

    for(int i=1;i<N;i++){
        bool f_viewable = true;
        for(int j=0;j<i;j++){
            if(H.at(i)<H.at(j))f_viewable = false;
        }
        if(f_viewable)num_viewable++;
    }

    cout << num_viewable << endl;
}