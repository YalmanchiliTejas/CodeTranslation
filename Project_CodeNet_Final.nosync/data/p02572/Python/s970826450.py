N,*A = map(int, open(0).read().split())
s = 0
m = 1000000007
for x in A:
    s = (s+x) % m
ans = 0
for x in A:
    s = (s-x) % m
    ans = (ans+x*s) % m
print(ans)