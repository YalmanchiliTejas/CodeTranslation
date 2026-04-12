N, X = map(int, input().split())

def ct(n, x):
    # print(n, x)
    if x == 1:
        if n == 0:
            return 1
        else:
            return 0
    elif x == L[n]//2+1:
        return P[n-1]+1
    elif x == L[n]:
        return P[n]
    elif x < L[n]//2+1:
        return ct(n-1,x-1)
    else:
        return P[n-1] + 1 + ct(n-1,x-(L[n]//2+1))

L = [1]
for i in range(50):
    L.append(L[-1]*2+3)
P = [1]
for i in range(50):
    P.append(P[-1]*2+1)

print(ct(N, X))
