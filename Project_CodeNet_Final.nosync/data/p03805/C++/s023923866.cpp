#include <iostream>
#include <vector>
#include <cmath>
#include <string> 
#include <cstdint>
#include <cstring>
//https://qiita.com/ofutonfuton/items/92b1a6f4a7775f00b6ae
 
using namespace std;
typedef long long ll;
bool** connection;
ll N, M;
int result = 0;

void saiki(bool* searched, int current){
    searched[current] = true;
    bool completed = true;
    for(ll i = 0; i < N; i ++){
        if(searched[i] == false){
            completed = false;
            break;
        }
    }   
    if(completed){
        result ++;
        return;
    }

    for(ll i = 0; i < N; i ++){
        if(connection[current][i] == true && searched[i] == false){
            bool* newSearched = new bool[N];
            for(ll i = 0; i < N; i ++){
                newSearched[i] = searched[i];
            }
            saiki(newSearched, i);
        }
    }
}

int main()
{
    cin >> N >> M;
    ll* a = new ll[M];
    ll* b = new ll[M];
    connection = new bool*[N];
    for(ll i = 0; i < N; i ++){
        connection[i] = new bool[N];
        for(ll n = 0; n < N; n ++){
            connection[i][n] = false;
        }
    }
    for(ll i = 0; i < M; i ++){
        cin >> a[i] >> b[i];
        a[i] --;
        b[i] --;
        connection[a[i]][b[i]] = true;
        connection[b[i]][a[i]] = true;
    }

    bool* newSearched = new bool[N];
    for(ll i = 0; i < N; i ++){
        newSearched[i] = false;
    }
    saiki(newSearched, 0);


    cout << result;
    
    return 0;
}