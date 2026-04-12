n = int(input())
a = list(map(int, input().split()))
ans = 0
a_sum = sum(a)
a_sum -= a[0]
for i in range(n - 1):
    ans += a[i] * a_sum
    a_sum -= a[i + 1]
ans %= 1000000007
print(ans)
