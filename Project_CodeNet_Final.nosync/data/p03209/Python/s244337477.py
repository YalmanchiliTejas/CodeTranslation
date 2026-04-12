n, x = map(int, input().split())
x -= 1
npl = [0] * (n+1)
lbl = [0] * (n+1)
npl[0] = 1
lbl[0] = 1
for i in range(1, n+1):
    npl[i] = 2*npl[i-1] + 1
    lbl[i] = 2*lbl[i-1] + 3

def rec(n, x):
    if x == 0:
        if n == 0:
            return 1
        else:
            return 0
    elif x < 1 + lbl[n-1]:
        return rec(n-1, x-1)
    elif x == 1+lbl[n-1]:
        return npl[n-1] + 1
    elif x == 2+2*lbl[n-1]:
        return 2*npl[n-1] + 1
    else:
        return npl[n-1] + 1 + rec(n-1, x-2-lbl[n-1])

print(rec(n, x))
