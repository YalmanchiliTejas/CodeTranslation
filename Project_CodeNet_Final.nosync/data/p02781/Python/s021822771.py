N=int(input())
K=int(input())
import sys
sys.setrecursionlimit(10**6)
def solve(N, K):
    if K==1:
        l=len(str(N))
        ans=0
        for i in range(l):
            if i!=l-1:
                ans+=9
            else:
                ans+=int(str(N)[0])
        #print(ans)
        return ans
    else:
        nextK=K-1
        l=len(str(N))
        ini=int(str(N)[0])
        res=ini*(10**(l-1))-1
        #print(res)
        if l>=K:
            ans=solve(res, K)
            nextN=int(str(N)[1:])
            ans+=solve(nextN, nextK)
            return ans
        else:
            return 0
ans=solve(N,K)
print(ans)