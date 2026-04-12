#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<functional>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector <int> > l(N, vector<int>(N));
    vector<int> v(N-1);
    for (int i=0; i< N-1; i++){
        v.at(i) = i+1;
    }
    for (int i=0; i< M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        l.at(a).at(b) = 1;
        l.at(b).at(a) = 1;
    }
    int r = 0;
    do{
        if(l.at(0).at(v.at(0))==0){
            continue;
        }
        int t = 0;
        for(int i=0; i<N-2; i++){
            if(l.at(v.at(i)).at(v.at(i+1)) == 0){
                break;
            }
            t++;
        }
        if (t == N-2){
            r++;
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << r << endl;
}
