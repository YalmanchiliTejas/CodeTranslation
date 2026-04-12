n = int(input())
a = list(map(int,input().split()))
sum_a = sum(a)

mod = 1000000000 + 7
ans = 0

for i in range(n):
    sum_a -= a[i]
    pdt = a[i] * sum_a
    ans += pdt

ans %= mod
print(ans)