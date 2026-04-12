import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n,x,m = list(map(int, input().split()))
v = x
seen = [0]*m
c = 0
val = 0
count = 0
tmp = 0
if n>m:
    while True:
        if seen[v]==2:
            break
        if seen[v]==1:
            count += 1
            tmp += v
        else:
            val += v
            c += 1
        seen[v] += 1
        v = (v**2)%m
    ans = val + ((n-c)//count) * tmp
    for i in range((n-c)%(count)):
        ans += v
        v = (v**2)%m
else:
    ans = 0
    v = x
    for i in range(n):
        ans += v
        v = (v**2)%m
print(ans)