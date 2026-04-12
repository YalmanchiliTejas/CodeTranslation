#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    vector<int> ans;

    while(cin>>N,N!=0){
        vector<int> point(N);
        for(int &i : point) cin>>i;

        sort(point.begin(),point.end());

        int ave = 0;

        for(int i = 1; i < N-1;i++) ave += point[i];

        ans.push_back(ave/(N-2));
    }

    for(int i:ans) cout<<i<<endl;

}
