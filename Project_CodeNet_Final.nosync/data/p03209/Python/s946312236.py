import sys
sys.setrecursionlimit(1000000)

N, X = map(int, input().split())

l = [1]
p = [1]
for i in range(1, 51):
    l.append(2*l[i-1]+3)
    p.append(2*p[i-1]+1)


def L(i, X):
    if i == 0:
        if X == 0:
            return 0
        else:
            return 1
    else:
        if X == 0:
            return 0
        elif 1 <= X < l[i-1]+2:
            return L(i-1, X-1)
        elif X == l[i-1]+2:
            return p[i-1]+1
        elif l[i-1]+2 < X < l[i]:
            return p[i-1]+1+L(i-1, X-l[i-1]-2)
        else:
            return p[i]


print(L(N, X))
