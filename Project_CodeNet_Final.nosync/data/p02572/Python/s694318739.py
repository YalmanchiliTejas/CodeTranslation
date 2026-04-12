N = int(input())
A = list(map(int, input().split()))

m = sum(A)
ans = 0

for i in range(N):
    t = A[i]
    m -= t
    ans += t * m

print(ans % (10 ** 9 + 7))
