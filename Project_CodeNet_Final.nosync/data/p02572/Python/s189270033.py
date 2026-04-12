n = int(input())
a = [int(x) for x in input().split()]
p = 10 ** 9 + 7

ans = 0
sq = 0
twoinv = pow(2, p - 2, p)

for i in range(n):
    ans += a[i]
    ans %= p
    sq += a[i] * a[i]
    sq %= p

ans = (ans * ans % p - sq) * twoinv % p
print(ans)