def DFS(N,X):
    if N==0:return 0 if X<=0 else 1
    elif X<=1+B[N-1]:
        return DFS(N-1,X-1)
    else:
        return P[N-1]+1+DFS(N-1,X-2-B[N-1])


n,x=map(int,input().split())
B,P=[1],[1]

for i in range(n):
    P.append(P[i]*2+1)
    B.append(B[i]*2+3)

print(DFS(n,x))