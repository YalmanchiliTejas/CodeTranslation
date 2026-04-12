#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(int n,int m){
    vector<int>v1;
    for(int i = 0;i < n;i++){
        int g;
        cin >> g;
        v1.push_back(g);
    }
    vector<int>v2;
    for(int i = 0;i < m;i++){
        int g;
        cin >> g;
        v2.push_back(g);
    }
    copy(v2.begin(),v2.end(),back_inserter(v1));
    sort(v1.begin(),v1.end());
    int max = v1[0];
    for(int i = 1;i < n+m;i++){
        if(max < v1[i] - v1[i - 1]){
            max = v1[i] - v1[i - 1];
        }
    }
    return max;
}
int main(){
    vector<int>a;
    while(1){
        int n ,m;
        cin >> n >> m;
        if(n == m && n == 0)break;
        
        a.push_back(solve(n,m));
    }
    for(int i = 0;i < a.size();i++){
        cout << a[i] << endl;
    }
    return 0;
}
