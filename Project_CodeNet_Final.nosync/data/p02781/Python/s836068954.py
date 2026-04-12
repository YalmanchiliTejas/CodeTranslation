N=input()
K=int(input())

LEN=len(N)

from functools import lru_cache
@lru_cache(maxsize=None)
def dfs(keta,use,coin):
    ANS=0

    if keta==LEN:
        if use==K:
            return 1
        return 0
        
    if coin==0:
        if use<K:
            ANS+=dfs(keta+1,use+1,0)*9
        ANS+=dfs(keta+1,use,0)

        return ANS

    else:
        kn=int(N[keta])

        if kn==0:
            return dfs(keta+1,use,1)

        ANS+=dfs(keta+1,use,0)
        ANS+=dfs(keta+1,use+1,0)*(kn-1)
        ANS+=dfs(keta+1,use+1,1)

        return ANS

print(dfs(0,0,1))