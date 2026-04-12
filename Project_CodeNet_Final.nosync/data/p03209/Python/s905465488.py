from sys import stdin

n,x = [int(x) for x in stdin.readline().rstrip().split()]
p = [1]
t = [1]
for i in range(1,n+1):
    p.append(p[i-1]*2+1)
    t.append(t[i-1]*2+3)

def f(n,x):
    if n == 0:
        return 1 if x == 1 else 0
    elif x == 1:
        return 0
    elif 1 < x <= 1 + t[n-1]:
        return f(n-1,x-1)
    elif x == t[n-1] + 2:
        return p[n-1] + 1
    elif t[n-1]+2 < x <= 2*t[n-1]+2:
        return f(n-1,x-2-t[n-1]) + p[n-1] + 1
    else:
        return 2*p[n-1]+1

print(f(n,x))