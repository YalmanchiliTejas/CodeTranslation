n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
s = sum(a)
s = s**2
t = 0
for i in a:
    t += i**2
s -= t
s //= 2
s %= mod
print(s)