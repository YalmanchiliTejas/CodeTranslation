#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){

    int n;
    cin >> n;

    vector<int> v;
    vector<int> m;

    int count = 1;


    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        if(i == 0){
            m.push_back(tmp);
        }else{
            if(tmp >= m[i - 1]){
                count++;
                m.push_back(tmp);
            }else{
                m.push_back(m[i - 1]);
            }
        }
    }

    cout << count << endl;



    return 0;
}