n = int(input())
aa = tuple(map(int, input().split()))

MOD = 10 ** 9 + 7

ans = 0
x = sum(aa)
for i in range(n):
    x -= aa[i]
    ans += aa[i] * x
    ans %= MOD
print(ans)