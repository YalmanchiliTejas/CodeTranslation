n = int(input())
a = list(map(int,input().split()))

mod = 10 ** 9 + 7
s = sum(a)
sum = 0

for i in range(n):
    s -= a[i]
    sum += s * a[i] % mod

sum %= mod
print(sum)