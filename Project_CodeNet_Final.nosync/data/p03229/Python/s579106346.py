n = int(input())
a = sorted(int(input()) for _ in range(n))
if n == 2:
    print(abs(a[0] - a[1]))
elif n%2 == 1:
    r1 = a[n//2] + a[n//2+1] + sum(a[n//2+2:])*2 - sum(a[:n//2])*2
    r2 = sum(a[n//2+1:])*2 - sum(a[:n//2-1])*2 - a[n//2-1] - a[n//2]
    print(max(r1, r2))
else:
    r1 = sum(a[n//2+1:])*2 + a[n//2] - sum(a[:n//2-1])*2 - a[n//2-1]
    print(r1)