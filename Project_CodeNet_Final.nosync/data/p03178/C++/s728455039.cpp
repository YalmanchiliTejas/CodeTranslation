
#include<iostream>
#include<cstring>
#define maxn  1000000007

using namespace std ;
#define ll long long int
int main()
{
string s ;
    ll d ;
    cin>> s>> d ;


    ll dp[s.length() +2 ] [ d] ={0} ;
    memset(dp , 0 , sizeof(dp)) ;
    dp[0][0] = 1 ;
    for(int i = 0 ;i < 10; i++ )
    {
        dp[1][i%d] = ( dp[1][i%d] +1 )%maxn ;

    }
    for(int i = 2 ; i< s.length() +1 ;i++ )
    {
        for(ll h = 0 ;h < d ;h++)
        {

            for( ll in =  0 ;in< 10 ;in++)
            {

ll  rem  =   (h - (in)%d + d  )%d  ;
dp[ i][h] = (dp[ i][h] + dp[i-1][rem ] )%maxn  ;

            }

        }




    }

 
 
     ll sum = 0 ;
     ll count = 0;
     for(ll i = 0 ; i < s.length() ;i++)
     {

         for(ll j = 0; j < s[i]-'0' ;j++ )
         {

             ll rem = j+sum ;
             rem%= d ;
             rem = (d-rem)%d ;

count = (count + dp[s.length()-i-1][rem]  )%maxn ;

         }
sum+= s[i]-'0' ;



     }
     count= ( count + dp[0][(d -sum%d ) %d ] )%maxn  ;
     

cout<<(maxn + count-1 )%maxn <<endl ;
}
