#include<bits/stdc++.h>
using namespace std ;

int main(){
    int h , w ;
    cin >> h >> w ;

    vector<vector<char>> data(h,vector<char>(w)) ;

    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++)
        {
            data.at(i).at(j) = s.at(j) ;
        }
        
    }
	vector<string> vec(h);
  
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k<h; k++)
            {
                if(data.at(k).at(j) == '#'){
                    break;
                }
                if(k == h-1){
                    data.at(i).at(j) ='x';
                }
            }
            for (int k = 0; k<w; k++)
            {
                if(data.at(i).at(k) == '#'){
                    break;
                }
                if(k == w-1){
                    data.at(i).at(j) ='x';
                  	vec.at(i) = "xx" ;
                }
            }
            
        }
        
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if(data.at(i).at(j) != 'x'){
                cout << data.at(i).at(j) ;
            }
        }
        if(vec.at(i)!="xx"){
          cout << endl;
        }        
    }
    
    
    
}