mod = 10**9+7
input()
a = map(int, input().split())
a = [x%mod for x in a]
def sum(arr):
    res = 0
    for e in arr:
        res += e
        res %= mod
    return res
print((sum(a)**2 - sum(x**2%mod for x in a)) * (10**9//2+4) % mod)