from collections import deque
def lower_bound(al, key):
    def isOk(a):
        return a<key

    ng = len(al)
    ok = -1

    while abs(ok-ng)>1:
        mid = (ok+ng)//2

        if isOk(al[mid]):
            ok = mid
        else:
            ng = mid

    return ok

n = int(input())
al = [int(input()) for _ in range(n)]
c = deque()

for a in al:
    if len(c) == 0:
        c.append(a)
        continue

    idx = lower_bound(c,a)
    if idx==-1:
        c.appendleft(a)
    else:
        c[idx] = a

print(len(c))