n,x = map(int,input().split())
p = [1]
q = [1]
for i in range(n):
    p.append(p[i]*2+1)
    q.append(q[i]*2+3)


def f(fn,fx):
    if fn == 0 and fx == 1:
        return 1
    elif fx == 1:
        return 0
    elif fx == q[fn]:
        return p[fn]
    elif fx == q[fn]//2+1:
        return 1+p[fn-1]
    elif 1 < fx < q[fn]//2+1:
        return f(fn-1, fx-1)
    else:
        return p[fn-1] + 1 + f(fn-1, fx-(q[fn-1]+2))


print(f(n,x))
