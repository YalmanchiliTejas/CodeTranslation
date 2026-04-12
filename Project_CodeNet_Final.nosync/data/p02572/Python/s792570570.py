import itertools

N = int(input())
A = list(map(int,input().split()))

acc = list(itertools.accumulate(A))
ans = 0
mod = 10**9 + 7

for i in range(N-1):
    ans += acc[i]*(acc[i+1] -acc[i])
    

print(ans%mod)