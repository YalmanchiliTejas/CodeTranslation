N = int(input())
A = list(map(int, input().split()))
ans = 0
m = 1000000007

s = 0
for i in range(N):
    ans += A[i] * s
    s += A[i]

print(ans % m)
