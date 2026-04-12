#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a.at(i) ;
    }
    vector<int> c ;
    c.push_back(a.at(0)) ;
    int min = a.at(0) ;
    for (size_t i = 1; i < n; i++)
    {
        bool newcolor = false ;
        if (a.at(i) <= min)
        {
            newcolor = true ;
        }
        
        
            
        
        if (newcolor == true)
        {
            c.push_back(a.at(i)) ;
        }
        else
        {
            for (int j = 0; j < c.size(); j++  )
            {
                if (c.at(j) < a.at(i))
                {
                    c.at(j) = a.at(i) ;
                    newcolor = false ;
                    break ;
                }
            }
           
        }
         min = c.at(c.size() - 1) ;
        
    }
    cout << c.size() << endl ;
    
}