import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N=int(input())
A=list(map(int,input().split()))

SUM=[0]*(N+1)
for i in range(N-1,-1,-1):
    SUM[i]=SUM[i+1]

    if (N-i)%2==1:
        SUM[i]+=A[i]

#print(SUM)
        
from functools import lru_cache
@lru_cache(maxsize=None)
def calc(i,select):
    rest=N-i

    if rest==0 or select==0:
        return 0

    if rest%2==1 and rest//2+1==select:
        return SUM[i]
    
    elif rest%2==0 and rest//2==select:
        return max(calc(i+1,select),A[i]+calc(i+2,select-1))

    elif rest%2==1 and rest//2==select:
        return max(calc(i+1,select),A[i]+calc(i+2,select-1))

print(calc(0,N//2))

    
