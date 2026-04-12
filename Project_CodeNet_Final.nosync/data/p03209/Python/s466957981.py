N, X = list(map(int,input().split()))

l = [1]
p = [1]
for i in range(N):
    l.append(2*l[i] + 3)
    p.append(2*p[i] + 1)

def f(N, X):
    if N == 0 and X > 0:
        return 1
    elif N == 0 and X <= 0:
        return 0
    elif X <= l[N-1] + 1:
        return f(N-1, X-1)
    else: # X > l[N-1] + 2:
        return p[N-1] + f(N-1, X - 2 - l[N-1]) + 1
    #elif X == l[N-1] + 2:
    #    return p[N-1] + 1

print(f(N, X))    
