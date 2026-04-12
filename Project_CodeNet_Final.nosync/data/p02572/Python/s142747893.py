N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7
a,s = 0,0
for i in range(N):
    a += s*A[i]
    s += A[i]
    a %= mod
print(a)