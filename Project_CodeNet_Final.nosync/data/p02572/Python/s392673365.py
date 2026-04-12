import itertools
n = int(input())
a = list(map(int,input().split()))
s = sum(a)
b = list(itertools.accumulate(a))
ans = 0
for i in range(n):
    ans += ((a[i] * (s - b[i])) % (10**9+7))
ans %= (10**9+7)
print(ans)