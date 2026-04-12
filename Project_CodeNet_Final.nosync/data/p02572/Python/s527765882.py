N = int(input())
A = list(map(int, input().split()))

mod = 1000000007


ans = 0
n = A[0]
for a in A[1:]:
    ans += a * n
    n += a

print(ans%mod)


