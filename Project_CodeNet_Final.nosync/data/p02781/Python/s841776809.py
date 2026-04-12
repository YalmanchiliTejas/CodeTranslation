from functools import lru_cache

def almost_everywhere_zero():
    N=int(input())
    K=int(input())
    print(f(N,K))
    
@lru_cache(None)
def f(n,k):
    if n<=10:
        if k==0:
            return 1
        if k==1:
            return n
        return 0
    div_n=n//10
    mod_n=n%10
    ans=f(div_n,k-1)*mod_n + f(div_n-1,k-1)*(9-mod_n) + f(div_n,k)
    return ans


almost_everywhere_zero()
