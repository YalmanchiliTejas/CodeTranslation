N = int(input())
A = list(map(int, input().split()))

a = [0]
for i in range(N):
    a.append(a[i] + A[i])

cnt = 0
for i in range(N-1):
    cnt += A[i] * (a[N] - a[i+1])

mod = 10 ** 9 + 7
ans = cnt % mod
print(ans)
