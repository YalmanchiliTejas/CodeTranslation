n = int(input())
l = list(map(int, input().split()))

mod = 10**9 + 7
s = sum(l)
res = 0

while len(l) > 1:
    i = l.pop()
    s -= i
    res += i * (s%mod)
    res %= mod
    
print(res)