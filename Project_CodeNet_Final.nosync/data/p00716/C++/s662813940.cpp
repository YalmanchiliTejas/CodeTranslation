#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    int first, year, ver, fee;
    double rate;
    int result = 0;
    vector<int> results;

    cin>>m;
    for (int i = 0; i < m; i++) {
        cin>>first;
        cin>>year;
        cin>>n;
        int temp;
        result = 0;
        for(int j = 0; j < n; j++){
            cin>>ver>>rate>>fee;
            temp = 0;
            if(ver){
                temp = first;
                for(int k = 0; k < year; k++){
                    temp += int(temp*rate) - fee;
                }
            }
            else{
                int first_temp = first;
                for(int k = 0; k < year; k++){
                    temp += int(first_temp*rate);
                    first_temp -= fee;
                    if(k == year-1){
                        temp += first_temp;
                    }
                }
            }
            if(result < temp){
                result = temp;
            }
        }
        results.push_back(result);
    }

    for(auto it = results.begin(); it != results.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}