#abc177 c
import sys,math,collections,itertools
input = sys.stdin.readline
m=10**9+7

N=int(input())
A=list(map(int,input().split()))
Asum = sum(A)
Asum_list = []
for i in range(N):
    Asum -=A[i]
    Asum_list.append(Asum)
ans = 0
for a,b in zip(A,Asum_list):
    ans = (ans + a*b)%m
print(ans)

