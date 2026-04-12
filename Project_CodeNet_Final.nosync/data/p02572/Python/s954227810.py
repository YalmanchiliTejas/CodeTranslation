n = int(input())
a = list(map(int, input().split()))
b = [0] * n
b[-1]= a[-1]
total = 0
mod = 10**9 + 7
cumsum = sum(a)
for i in range(n-1):
    cumsum -= a[i]
    total = (total + (a[i] * cumsum) % mod) % mod
print(total)