import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n,x = list(map(int, input().split()))
l = [None]*(n+1)
ps = [None]*(n+1)
v = 1
vp = 1
for i in range(n+1):
    l[i] = v
    ps[i] = vp
    v = 2*v + 3
    vp = 2*vp + 1
def sub(n,x):
    if n==0:
        if x==1:
            return 1
        else:
            return 0
    if x==1:
        return 0
    elif x==l[n]:
        return ps[n]
    elif x==l[n-1]+2:
        return ps[n-1]+1
    elif x<l[n-1]+2:
        return sub(n-1,x-1)
    else:
        return sub(n-1,x-2-l[n-1]) + ps[n-1] + 1
ans = sub(n,x)
print(ans)