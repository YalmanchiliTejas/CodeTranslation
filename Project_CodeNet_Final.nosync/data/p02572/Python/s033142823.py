n = int(input())
a = list(map(int, input().split()))

a_sum = sum(a)
ans = 0
for i in range(n):
    a_sum -= a[i]
    ans += a[i] * a_sum

ans = int(ans % (10**9+7))
print(ans)