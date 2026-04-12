import sys
sys.setrecursionlimit(10**6)
from functools import lru_cache

def solve(n,x):
    total=[1]
    paty=[1]
    for i in range(50):
        total.append(total[i]*2+3)
        paty.append(paty[i]*2+1)

    @lru_cache(maxsize=None)
    def f(N,X):
        if N==0 and X<=0:
            return 0
        elif N==0 and X>0:
            return 1
        elif X<=total[N-1]+1:
            return f(N-1, X-1)
        else:
            return paty[N-1]+1+f(N-1, X-total[N-1]-2)
    return print(f(n,x))

if __name__=='__main__':
    n,x=map(int,input().split())
    solve(n,x)
