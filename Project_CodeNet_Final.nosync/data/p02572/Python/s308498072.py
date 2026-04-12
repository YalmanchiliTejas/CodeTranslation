import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n = int(input())
A = list(map(int,input().split()))
S = sum(A) % mod
for i in range(n):
  S =(S- A[i]) % mod
  ans += S * A[i]
  ans %= mod
print(ans)