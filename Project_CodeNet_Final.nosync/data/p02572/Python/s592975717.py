n = int(input())
A = list(map(int, input().split()))

mod = 10**9+7

count = 0

num = sum(A) % mod

ans = 0
for a in A[:-1]:
    num = num-a
    ans = (ans+a*num) % mod

print(ans)
