n = int(input())
a = list(map(int,input().split()))

suma = sum(a)**2
sums = 0
for i in range(n):
    sums += a[i]*a[i]

ans = (suma - sums) // 2
ans %= 1000000007

print(int(ans))
