def DFS(N,X):
    if N==0:return 1
    elif X==1:return 0
    elif 1<X<=1+B[N-1]:return DFS(N-1,X-1)
    elif X==2+B[N-1]:return P[N-1]+1
    elif 2+B[N-1]<X<=2+2*B[N-1]:return P[N-1]+1+DFS(N-1,X-2-B[N-1])
    elif X==2*B[N-1]+3:return 2*P[N-1]+1


n,x=map(int,input().split())

P,B=[1],[1]
for i in range(n):
    P.append(P[i]*2+1)
    B.append(B[i]*2+3)

print(DFS(n,x))