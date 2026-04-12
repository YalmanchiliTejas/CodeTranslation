N,X=map(int,input().split())
M,P=[1],[1]
for i in range(1,N+1):
    M.append(M[-1]*2+3)
    P.append(P[-1]*2+1)

def counter(N,X):
    if N==0:
        if X<=0:
            return 0
        else:
            return 1
    elif X==1:
        return 0
    elif X<=1+M[N-1]:
        return counter(N-1,X-1)
    else:
        return P[N-1]+1+counter(N-1,X-2-M[N-1])

print(counter(N,X))