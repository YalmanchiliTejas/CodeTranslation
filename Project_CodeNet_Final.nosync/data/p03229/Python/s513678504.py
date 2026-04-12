n = int(input())
a = [int(input()) for i in range(n)]
a.sort()

l = a[n-1]
r = a[0]
o = abs(l - r)
for i in range(n//2):
    o += abs(r - a[i])
    o += abs(l - a[n-i-1])
    l = a[i]
    r = a[n-i-1]
if n%2 != 0:
    i = n//2
    o += max(abs(l-a[i]) , abs(r-a[i]))


print(o)