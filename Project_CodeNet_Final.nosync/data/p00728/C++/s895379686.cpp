#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    while(1){
        vector<int> point;
        int n,x;
        long long sum=0;
        cin >> n;
        if(n==0)    break;
        while(n--){
            cin >> x;
            point.push_back(x);
        }
        sort(point.begin(),point.end());
        for(int i=1;i<point.size()-1;i++){
            sum+=point[i];
        }
        cout << sum/(point.size()-2) << "\n";
        point.clear();
    }
}