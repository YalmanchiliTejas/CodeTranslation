n = int(input())
a = list(map(int, input().split()))
ans = 0
c = sum(a)

for i in range(n - 1):
    c = c - a[i]
    ans += a[i] * c

print(ans % (10 ** 9 + 7))    