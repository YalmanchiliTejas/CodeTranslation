#include<bits/stdc++.h>
using namespace std;

int pow9by(int n){
    int ret=1;
    for(int i=0; i<n; i++){
        ret*=9;
    }
    return ret;
}

int nCk(int n,int k){
    if(n<k) return 0;
    int ret=1;
    for(int i=0; i<k; i++){
        ret*=n-i;
        ret/=i+1;
    }
    return ret;
}
int ctoi(const char c){
    return c-'0';
}
int main(){
    string N;
    int K;
    cin >> N >> K;
    vector<int> place;
    vector<int> num;
    for(int i=0; i<N.length(); i++){
        if(ctoi(N.at(i))){
            place.push_back(N.length()-i);
            num.push_back(ctoi(N.at(i)));
        }
        if(place.size()==K) break;
    }
    long long ans=0;
    if(N.length()<K || (N.length()==K&&N.at(0)=='1')){
        ans=0;
    }else{
        if(place.size()==K) ans++;
        for(int i=0; i<place.size(); i++){
            ans+=(long long)(num.at(i)-1)*nCk(place.at(i)-1,K-i-1)*pow9by(K-i-1);
            ans+=(long long)nCk(place.at(i)-1,K-i)*pow9by(K-i);
        }
    }
    cout << ans;
    return 0;
}
