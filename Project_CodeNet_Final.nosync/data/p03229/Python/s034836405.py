n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))

a.sort(reverse = True)

if n % 2 == 0:
    print((sum(a[:n//2-1]) - sum(a[n//2+1:]))*2 + a[n//2-1] - a[n//2])
else:
    print(max((sum(a[:n//2]) - sum(a[n//2+2:]))*2 - sum(a[n//2:n//2+2]), (sum(a[:n//2-1]) - sum(a[n//2+1:]))*2 + sum(a[n//2-1:n//2+1])))
