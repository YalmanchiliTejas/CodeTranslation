#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int a[M], b[M];
    int count;
    bool flag;

    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i];
    }

    vector<int> path(N);
    iota(path.begin(), path.end(), 1);

    count=0;
    do{

        for(int i=0; i<N-1; i++){
            flag=false;
            for(int j=0; j<M; j++){
                if( path.at(i)==a[j] && path.at(i+1)==b[j]  ){
                    flag=true;
                }else if( path.at(i)==b[j] && path.at(i+1)==a[j]  ){
                    flag=true;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            //for(auto x : path) cout << x << " "; cout << endl;
            count++;
        }
    }while( next_permutation( next(path.begin()), path.end() ) );

    cout << count << endl;

    return 0;
}