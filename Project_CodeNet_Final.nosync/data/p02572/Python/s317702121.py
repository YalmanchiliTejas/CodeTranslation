n = int(input())
a = list(map(int,input().split()))
b = 0
d = sum(a)
for m in range(n-1):
    d = d -a[m]
    b = b + a[m]*d
    if b >= 10**9+7:
        b = b % (10**9+7)
print(b)