n = int(input())
mod = 10 ** 9 + 7
A = list(map(int, input().split()))
A = [0] + A
ans = 0
sm = 0
for i, a in enumerate(A[1:]):
    sm += A[i]
    sm %= mod
    ans += a * sm
    ans %= mod
print(ans)