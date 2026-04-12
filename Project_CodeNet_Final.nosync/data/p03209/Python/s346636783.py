N, X = map(int, input().split())

C, P = [1], [1]
for _ in range(N):
    C.append(C[-1]*2 + 3)
    P.append(P[-1]*2 + 1)

def f(n, x):
    if n==0:
        return 0 if x <= 0 else 1
    elif x <= C[n]//2:
        return f(n-1,x-1)
    elif x == C[n]//2+1:
        return P[n-1]+1
    else:
        return P[n-1]+1+f(n-1,x - C[n-1] - 2)

print(f(N,X))
