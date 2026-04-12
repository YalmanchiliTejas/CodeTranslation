n = int(input())
s=0
a = list(map(int, input().split()))
b = sum(a)
for i in range(n):
    b -= a[i]
    s += a[i]*b
    s = s % ((10**9)+7)
print(s)