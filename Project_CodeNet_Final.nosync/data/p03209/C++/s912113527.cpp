#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long> lengths(51);
vector<long> pates(51);

long burger(long level, long length){
    if(level == 0){
        if(length <= 0)return 0;
        else return 1;
    }
    else if(length <= 1 + lengths.at(level-1)){
        return burger(level-1, length-1);
    }
    else{
        return pates.at(level-1) + 1 + burger(level-1, length-lengths.at(level-1)-2);
    }
}

int main(){

    long n,x;
    cin >> n >> x;

    lengths.at(0) = 1;
    pates.at(0) = 1;
    for(int i=1;i<=50;i++){
        lengths.at(i) = lengths.at(i-1) * 2 + 3;
        pates.at(i) = pates.at(i-1) * 2 + 1;
    }

    cout << burger(n, x) << endl;

    return 0;
}
