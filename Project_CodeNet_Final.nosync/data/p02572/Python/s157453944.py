n = int(input())
a = list(map(int, input().split()))
A = sum(a)
s = 0
for i in range(n-1):
    A = A - a[i]
    b = (a[i]*A)%(10**9+7)
    s = s + b
print(s%(10**9+7))