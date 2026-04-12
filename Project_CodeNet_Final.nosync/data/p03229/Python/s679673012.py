import sys

read = sys.stdin.read
n, *a = map(int, read().split())
a.sort()
x = 2*sum(a[(n+1)//2:]) - 2*sum(a[:(n+1)//2])
y = 2*sum(a[n//2:]) - 2*sum(a[:n//2])
if n % 2 == 1:
    x += a[n//2-1] + a[n//2]
    y -= a[n//2] + a[n//2+1]
else:
    x -= a[n//2] - a[n//2-1]
    y -= a[n//2] - a[n//2-1]
    y 
print(max(x, y))
