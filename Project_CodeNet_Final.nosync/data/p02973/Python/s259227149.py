def bi(l,x):
    ok = len(l)
    ng = -1
    while ok-ng > 1:
        mid = (ng+ok)//2
        if l[mid] < x:
            ok = mid
        else:
            ng = mid
    return ok

n = int(input())
a = [int(input()) for _ in range(n)]
t = [-1]
m = 1
for x in a:
    c = bi(t,x) 
    if c == m:
        t.append(x)
        m += 1
    else:
        t[c] = x
print(m)
