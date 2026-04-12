N,X = map(int,input().split())

P = [1]
H = [1]
for i in range(1,51):
    P.append(P[i-1]*2+1)
    H.append(H[i-1]*2+3)

def r(n,x):
    if x<=n:
        return 0
    if x==H[n]:
        return P[n]
    if x>=H[n-1]+2:
        return P[n-1]+1+r(n-1,x-H[n-1]-2)
    else:
        return r(n-1,x-1)

print(r(N,X))
