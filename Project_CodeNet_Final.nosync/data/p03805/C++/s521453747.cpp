#include <bits/stdc++.h>
using namespace std;

int main(){
    int f,d,n,m,cnt=0;
    cin >> n >> m;
    vector<int> num(n);
    for(int i=0;i<n;i++)
        num.at(i)=i;
    vector<vector<bool>> rt(n,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        cin >> f >> d;
        rt.at(f-1).at(d-1) = rt.at(d-1).at(f-1) = true; 
    }
    do{
        bool pos=true;
        for(int i=0;i+1<n;i++)
            if(!rt.at(num.at(i)).at(num.at(i+1)))
                pos=false;
        if(pos)
            cnt++;
    }while(next_permutation(num.begin()+1,num.end()));
    cout << cnt << endl;
}