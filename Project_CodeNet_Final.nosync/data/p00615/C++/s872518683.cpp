#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;

    while(cin >> n >> m, n != 0 || m != 0){
        vector<int> tl(n+m+1);
        int max = 0;
        tl[0] = 0;
        for(int i=1; i<tl.size(); i++){
            cin >> tl[i];
        }

        sort(tl.begin(), tl.end());

        for(int i=0; i<tl.size()-1; i++){
            int tmp = tl[i+1] - tl[i];
            if(max < tmp){
                max = tmp;
            }
        }


        cout << max << endl;
    }

    return 0;
}