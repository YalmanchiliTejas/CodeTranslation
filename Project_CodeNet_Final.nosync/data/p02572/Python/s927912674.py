n = int(input())
a = list(map(int, input().split()))

sum_sq_a = 0
for i in range(n):
    sum_sq_a += a[i]**2

ans = ((sum(a))**2 - sum_sq_a) // 2

print(ans % (10**9 + 7))
