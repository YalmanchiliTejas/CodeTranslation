n = int(input())
A = list(map(int, input().split()))

mod = 10**9+7

cs = [0]
for a in A:
    cs.append(cs[-1]+a)
cs = cs[1:]

ans = 0
for i in range(n):
    ans += A[i] * (cs[-1]-cs[i])
    ans %= mod
print(ans)