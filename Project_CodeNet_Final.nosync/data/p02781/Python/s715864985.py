import itertools

def comb(a,b):
    if a<=0:
        return 0
    if b==1:
        return a
    elif b==2:
        return a*(a-1)//2
    else:
        return a*(a-1)*(a-2)//6

def tmp(L, K):
    ret=[]
    if K==1:
        bases=itertools.combinations(range(L+1),K)    
        for b in bases:
            ret+=[ k*10**b[0] for k in range(1,10)]
    if K==2:
        bases=itertools.combinations(range(L+1),K)
        kk=list(itertools.product(range(1,10),range(1,10)))
        for b in bases:
            ret+=[ k[0]*10**b[0] + k[1]*10**b[1] for k in kk]
    return ret

Nst=input()
K=int(input())
L=len(Nst)
N1=int(Nst[0])

if K==1:
    ans=comb( L-1, K) * 9 + N1
elif K>=2:
    ans=comb( L-1, K) * 9**(K) + comb( L-1, K-1) * 9**(K-1) *(N1-1)
    lst=[ 10**(L-1)*N1 + a for a in tmp(L-1, K-1)]
    ans+=sum([x <= int(Nst) for x in lst])
print (ans)