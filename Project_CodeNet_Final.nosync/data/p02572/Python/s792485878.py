n = int(input())
a = list(map(int,input().split()))

sums = 0
for i in range(n):
    sums += a[i]

sums *= sums;
ans = sums;

for i in range(n):
    ans -= a[i]*a[i]
ans //= 2
ans %= 1000000007
print(int(ans))
