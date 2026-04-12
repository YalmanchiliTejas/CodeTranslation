#include <bits/stdc++.h>

using namespace std;


int main()
{
    long N, tmp;
    long vec_size;
    long small, big;
    vector<long> vec;

    small = big = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());


    vec_size = vec.size();
    for (int i = 0; i < vec_size/2; i++) {
        small+= vec[i]*2;
    }
    for(int i = vec_size/2; i < vec_size; i++) {
            big+= vec[i]*2;
        }
    
    if (vec_size % 2 == 0) {
        small-=vec[vec_size/2-1];
        big-=vec[vec_size/2];
    } else {
           
        big-=vec[vec_size/2]+vec[vec_size/2+1];
        
        if (vec[vec_size/2]*2 - vec[vec_size/2+1]-vec[vec_size/2-1] < 0) {
            small+=vec[vec_size/2]*2 - vec[vec_size/2+1]-vec[vec_size/2-1];
        }
    }
    
    cout << big-small << endl;

    return 0;   
}