n, x = map(int, input().split())

t = [1]
p = [1]

for i in range(1, n+1):
    t.append(3+2*t[i-1])
    p.append(1+2*p[i-1])

def pathi(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= t[n-1] + 1:
        return pathi(n-1, x-1)
    else:
        return p[n-1] + 1 + pathi(n-1, x-t[n-1]-2)

print(pathi(n, x))