N=int(input())
A=list(map(int,input().split()))

dpx=[[0 for i in range(0,N)] for i in range(0,N+1)]
dpy=[[0 for i in range(0,N)] for i in range(0,N+1)]

for i in range(1,N+1):
    for j in range(0,N):
        if N>j+i-1 and i!=1:
            dpx[i][j]=max(dpy[i-1][j+1]+A[j],dpy[i-1][j]+A[j+i-1])
            dpy[i][j]=min(dpx[i-1][j+1]-A[j],dpx[i-1][j]-A[j+i-1])
        elif N>j+i-1 and i==1:
            dpx[i][j]=A[j]
            dpy[i][j]=-A[j]

print(dpx[N][0])