import sys
sys.setrecursionlimit(100000000)

N,X=map(int,raw_input().split())

height=[-1]*51
niku=[-1]*51
height[0]=1
niku[0]=1

for i in range(1, N+1):
    height[i]=2*height[i-1]+3
    niku[i]=2*niku[i-1]+1

def rec(l, x):
    if x==1:
        if l==0:
            return 1
        else:
            return 0
    
    if x < 1+height[l-1]+1:
        return rec(l-1, x-1)
    elif x == 1+height[l-1]+1:
        return 1 + niku[l-1]
    elif x <= height[l] - 1:
        return niku[l-1] + 1 + rec(l-1, x-height[l-1]-2)
    else:
        return 2*niku[l-1]+1
print(rec(N, X))



    

