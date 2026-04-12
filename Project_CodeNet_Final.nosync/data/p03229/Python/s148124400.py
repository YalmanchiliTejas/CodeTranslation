n = int(input())
a = [0]*n
for i in range(n):
    a[i] = int(input())
a.sort()
if n%2 == 0:
    print(2*(sum(a[n//2:])-sum(a[:n//2]))-(a[n//2]-a[n//2-1]))
else:
    print(2*(sum(a[n//2+1:])-sum(a[:n//2]))-min(a[n//2]-a[n//2-1],a[n//2+1]-a[n//2]))