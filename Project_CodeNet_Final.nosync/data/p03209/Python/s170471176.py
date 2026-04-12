def hum(L,X):
    if L == 0:
        if X <= 0:
            return 0
        else:
            return 1
    elif X <= 1 + t[L-1]:
        return hum(L-1,X-1)
    elif X <= 2 + 2 * t[L-1]:
        return p[L-1] + hum(L-1,X-2-t[L-1]) + 1
    else:
        return 2 * p[L-1] + 1

n, x = map(int,input().split())
t = [1]
p = [1]
for i in range(n):
    t.append(t[i] * 2 + 3)
    p.append(p[i] * 2 + 1)
print(hum(n,x))