n = int(input())
a = list(map(int,input().split()))
p = 0
q = a[0]
for i in range(1,n):
    p += q*a[i]
    p %= 1000000007
    q += a[i]
    q %= 1000000007
print(p)