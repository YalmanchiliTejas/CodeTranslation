#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> num(N);
    for(int i=0;i<N;i++){
        cin >> num[i];
    }
    sort(num.rbegin(),num.rend());

    long long sum=0;
    for(int i=0;i<N/2;i++){
        if(i==0){
            sum+=num.at(i)-num.at(N-1)+num.at(i)-num.at(N-2);
        }
        else{
            sum+=num.at(i)-num.at(N-i)+num.at(i)-num.at(N-i-2);
        }
        //if(N%2==0){
          //  sum+=num.at(N/2-1)-num.at(N/2+1);
        //}
    }


    sort(num.begin(),num.end());
    //cout << num[0] << num[1] << num[2] << endl;
    long long sumb=0;
    for(int i=0;i<N/2;i++){
        if(i==0){
            sumb+=-num.at(i)+num.at(N-1)-num.at(i)+num.at(N-2);
        }
        else{
            sumb+=-num.at(i)+num.at(N-i)-num.at(i)+num.at(N-i-2);
        }
        //if(N%2==0){
         //  sum+=num.at(N/2-1)-num.at(N/2+1);
        //}
    }
    //cout << sum << sumb << endl;
    cout << max(sumb,sum) << endl;
    //cout << sum << sumb << endl;

}