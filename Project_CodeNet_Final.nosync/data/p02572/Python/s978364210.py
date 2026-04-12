N = int(input())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7
all = sum(A)
ans = all * all
for a in A:
    ans -= a * a
ans //= 2
ans %= MOD
print(ans)
