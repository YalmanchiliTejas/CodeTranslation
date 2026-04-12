n = int(input())
a = list(map(int, input().split()))
c = 10 ** 9 + 7
ans = 0
s = 0
for i in range(n-1, -1, -1):
    ans += s * a[i]
    s += a[i]
print(ans % c)