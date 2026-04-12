n = int(input())
x = list(map(int, input().split()))
a = sorted(range(n), key=lambda i: x[i])
l = x[a[n//2-1]]
r = x[a[n//2]]
b = [0]*n
for i, j in enumerate(a):
    if i < n//2:
        b[j] = r
    else:
        b[j] = l
for e in b:
    print(e)