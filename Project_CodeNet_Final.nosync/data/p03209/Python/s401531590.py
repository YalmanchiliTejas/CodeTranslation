import sys
input = sys.stdin.readline

N, X = map(int, input().split())
l, p = [1], [1]

for i in range(N):
    l.append(l[i]*2 + 3)
    p.append(p[i]*2 + 1)

def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + l[N-1]:
        return f(N-1, X-1)
    else:
        return p[N-1] + 1 + f(N-1, X-2-l[N-1])
    
print(f(N, X))
