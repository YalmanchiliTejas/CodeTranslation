n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
total = sum(a)
ret = 0
for i in range(n):
    ret += ((total - a[i]) * a[i])
print((ret//2) % mod)
