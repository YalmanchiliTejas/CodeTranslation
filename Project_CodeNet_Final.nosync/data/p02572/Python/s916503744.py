n = int(input())
a = list(map(int, input().split()))
b = [0] * n
b[-1]= a[-1]
total = 0
mod = 10**9 + 7
for i in range(n-2, 0, -1):
    b[i] = a[i] + b[i + 1]
for i in range(n-1):
    total = (total + (a[i] * b[i + 1]) % mod) % mod
print(total)
