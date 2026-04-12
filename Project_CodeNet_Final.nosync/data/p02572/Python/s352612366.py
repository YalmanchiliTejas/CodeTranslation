mod = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
s = sum(a) - a[0]
res = 0
for i in range(n-1):
    res += s * a[i]
    s -= a[i+1]
print(res % mod)