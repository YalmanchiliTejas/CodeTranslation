#include<bits/stdc++.h>
using namespace std;

long long burger[52],patty[52];
long long n, x;
long long ans=0;


void f(int n)
{
    if(x == burger[n])
	{
		// µÝ¹éÖÕÖ¹Ìõ¼þ 
		// ²âÊÔÊý¾Ýn=2,x=3»á½øÈë±¾·ÖÖ§ 
		ans += patty[n];
		return;	
	}
    else if(x < burger[n])
	{
		if(x)	// x>0
	    {
	        x--;	// ×îµ×ÏÂÄÇÒ»²ãÊÇbun²»ÊÇpatty£¬¼õµô 
	        if(x > burger[n-1])
	        {
	        	ans += patty[n-1];
	            x -= burger[n-1];
	            
	            // ¼ÓÉÏÖÐ¼äÄÇÒ»²ãµÄpatty 
				ans++;
				x--;
				
				// x > burger[n-1]·ÖÎªÁ½ÖÖÇé¿ö£º
				// Ò»ÊÇx>burger[n-1]+1£¬ÕâÀï1Ö¸µÄÊÇÖÐ¼äµÄpatty²ã£¬ÕâÖÖÇé¿ö½øÏÂÃæµÄif
				// ¶þÊÇx==burger[n-1]+1£¬ÕâÖÖÇé¿ö½øÏÂÃæµÄelse 
	            if(x)
				{
					f(n-1);
				}
				else // x==0ÊÇÑ­»·ÖÕÖ¹Ìõ¼þ£¬¿ÉÒÔÊ¡ÂÔ²»Ð´ 
				{
					// ²âÊÔÊý¾Ýn=2,x=4»á½øÈë±¾·ÖÖ§ 
					return;
				} 
				
	        }
	        else // x<=burger[n-1]
			{
				f(n-1);
			}
		}
		else // x==0ÊÇÑ­»·ÖÕÖ¹Ìõ¼þ£¬¿ÉÒÔÊ¡ÂÔ²»Ð´ 
		{ 
			// ²âÊÔÊý¾Ýn=2,x=1»òn=2,x=2»á½øÈë±¾·ÖÖ§ 
			return;
		}
    }
}


int main()
{
    scanf("%lld%lld",&n, &x);
    burger[0] = 1, patty[0] = 1;	// ³õÊ¼»¯n = 0Ê± 
    
    for(int i = 1; i <= 50; i++)
    {
    	// ¼ÆËã1²ã~50²ãµÄºº±¤×Ü²ãÊýºÍ¶ÔÓ¦µÄpatty²ãÊý 
        burger[i] = burger[i-1] * 2 + 3; // ºº±¤µÄ×Ü²ãÊý 
        patty[i] = patty[i-1] * 2 + 1;	 // patty²ãÊý 
        //cout << "n=" << i << ",ºº±¤×Ü²ãÊýºÍpatty²ãÊý£º" << burger[i] << ',' << patty[i] << '\n'; 
    }
    
    f(n);
    printf("%lld\n", ans);
    
    return 0;
}