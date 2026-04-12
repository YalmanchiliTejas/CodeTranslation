import sys
sys.setrecursionlimit(10**6)
n,x=map(int, input().split())

total=[1]
paty=[1]
for i in range(n):
    total.append(total[i]*2+3)
    paty.append(paty[i]*2+1)

def rec(N, X): 
    if N==0 and X<=0:
        return 0 
    elif N==0 and X>0:
        return 1
    elif X<=1+total[N-1]:
        return rec(N-1, X-1)
    else:
        return paty[N-1] + 1 + rec(N-1, X-2-total[N-1])

print(rec(n, x))