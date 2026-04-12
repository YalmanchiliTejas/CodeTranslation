import sys
import  math
import fractions
from collections import defaultdict
import copy
stdin = sys.stdin
     
ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

N=int(input())
A=nl()
mod=10**9+7
sum_a=sum(A)
ans=0
for i in range(N):
    sum_a=sum_a-A[i]
    ans+=sum_a*A[i]
    ans%=mod

print(ans)


    