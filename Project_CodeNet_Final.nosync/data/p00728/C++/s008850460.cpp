#include <cstdio>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

main(){
    int n;

    while(cin >> n){
        if(n == 0) break;

        vector <int> vec;
        for(int i = 0 ; i < n ; i++){
            int q;
            cin >> q;

            vec.push_back(q);
        }

        sort(vec.begin(),vec.end());

        int sum = 0;

        for(int i = 1 ; i < n-1 ; i++){
            sum+=vec[i];
        }

        cout << sum/(n-2) << endl;
    }
    return 0;
}