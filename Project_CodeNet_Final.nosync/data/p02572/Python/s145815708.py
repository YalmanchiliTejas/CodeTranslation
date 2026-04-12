n = int(input())
a = list(map(int, input().split()))
m = 1000000007
s = 0
suma = sum(a)
for i in range(n):
    suma -= a[i]
    s += a[i] * suma
print(s % m)