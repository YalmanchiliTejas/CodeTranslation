n = int(input())
A = [int(input()) for _ in range(n)]
a=sorted(A)
# print(n//2)
if n%2:
    print(sum(a[-n//2+1:])*2 - sum(a[:n//2])*2 - min(a[n//2+1]-a[n//2],a[n//2]-a[n//2-1]))
else:
    print(sum(a[n//2+1:])*2 -sum(a[:n//2-1])*2 +a[n//2] -a[n//2-1])