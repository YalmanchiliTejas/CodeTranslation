import sys

def f(l,beg,end):
    if beg==end:
        dp[beg][end]=l[beg]
        return l[beg]
    if beg+1==end:
        dp[beg][end] = max(l[beg],l[end]) 
        return max(l[beg],l[end])
    if dp[beg][end]!=-1:
        return dp[beg][end]
    ans1=l[beg]+min(f(l,beg+2,end),f(l,beg+1,end-1))
    ans2=l[end]+min(f(l,beg,end-2),f(l,beg+1,end-1))
    dp[beg][end]=max(ans1,ans2)
    return max(ans1,ans2)

n = int(input())
l = list(map(int, input().split()))
tl = sum(l)
dp=[]
for _ in range(n):
    dp.append([-1]*n)
a = f(l,0,n-1)
b = tl-a
print(a-b)