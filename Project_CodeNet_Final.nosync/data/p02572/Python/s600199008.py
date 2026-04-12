n = int(input())
al = list(map(int, input().split()))
s = sum(al)
ss = 0
m = 10**9+7
d = 500000004
for a in al:
    ss += a*a
print(((s*s-ss)%m*d)%m)