m = 10 ** 9 + 7
n = int(input())
a = list(map(int, input().split()))
x = 0
s = [x := x + c for c in a]
ans = 0

for i in range(n - 1):
    ans += a[i] * (s[n-1]-s[i])
    ans %= m
print(ans)