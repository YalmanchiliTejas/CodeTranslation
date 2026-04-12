N=int(input())
X=list(map(int,input().split()))
Y=[X[i] for i in range(N)]
Y.sort()
for i in range(N):
    if X[i]<Y[N//2]:
        B=Y[N//2]
    else:
        B=Y[(N//2)-1]
    print(B)