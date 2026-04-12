#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, i, j;
    cin>>h>>w;
    vector<int> v1, v2;
    bool res;

    string arr[h];

    for(i=0;  i<h; i++){
        cin>>arr[i];
    }
    for(i=0; i<h; i++){
        res = true;
        for(j=0; j<w; j++){
            if('.' != arr[i][j]){
                res = false;
            }

        }
        if(res == false)
            v1.push_back(i);
    }

    for(j=0; j<w; j++){
        res = true;
        for(i=0; i<h; i++){
            if('.' != arr[i][j])
                res = false;
        }
        if(res == false)
            v2.push_back(j);
    }

    for(i=0; i<h; i++){
        if( (find(v1.begin(), v1.end(), i) != v1.end() )){

            for(j=0; j<w; j++){
                if(find(v2.begin(), v2.end(), j) != v2.end()){

                    cout<<arr[i][j];
                }

            }
            cout<<endl;
        }

    }
}
