n = int(input())
a = list(map(int, input().split()))
s = 0
ans = 0
mo = 10 ** 9 + 7
for i in range(n):
    ans += s * a[i]
    s += a[i]
print(ans % mo)