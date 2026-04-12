#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

long long f(long long x, long long m){
    return (x *x) % m;
}

int main(){
    long long n, x, m;
    cin >> n >> x >> m;

    set<long long> T;
    long long now = x;
    T.insert(now);
    long long start;
    for(long long i = 0; i < m; i++){
        //printf("i %lld %lld\n", i+1, now);
        now = f(now, m);
        if(T.find(now) == T.end()) T.insert(now);
        else{
            start = now;
            break;
        }
    }

    bool find = false;
    vector<long long> loop;
    long long dist = 0;
    //printf("start %lld\n", start);
    now = x;
    for(long long i = 0; i < m; i++){
        //printf("i %lld %lld\n", i+1, now);
        now = f(now, m);
        if(now == start and find == false){
            //printf("find\n");
            find = true;
            dist = i+1;
        }
        else if(now == start and find == true) break;

        if(find == true){
            loop.push_back(now);
        }
    }
    //printf("dist %lld\n", dist);

    long long fre = 0;
    for(long long i = 0; i < loop.size(); i++) fre += loop[i];

    long long ans = 0;
    if(n <= dist) {
        now = x;
        for(long long i = 0; i < n; i++){
            ans += now;
            now = f(now, m);
        }
    }
    else{
        now = x;
        for(long long i = 0; i < dist; i++){
            ans += now;
            now = f(now, m);
        }
        long long r = (n-dist)/((long long)loop.size());
        long long amari = (n-dist) % ((long long)loop.size());

        ans += fre * r;
        for(long long i = 0; i < amari; i++) ans += loop[i];
    }

    cout << ans << endl;
    return 0;
}