import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,input().split()))

ANS=0
B=[A[0],A[1]]
C=[]
D=A[-1]

for i in range(N-1):
    if A[i*3+2]==A[i*3+3]==A[i*3+4]:
        ANS+=1
    else:
        C.append((A[i*3+2],A[i*3+3],A[i*3+4]))

DP=[[-1]*(N+1) for i in range(N+1)]
MAXDP=[-1]*(N+1)
SCMAX=0

DP[B[0]][B[1]]=DP[B[1]][B[0]]=0
MAXDP[B[0]]=0
MAXDP[B[1]]=0

for x,y,z in C:
    #for d in DP:
    #    print(*d)
    #print()
    #print(x,y,z)
    #print()

    NLIST=[]
    SCMAX2=0

    NMAXDP=[i for i in MAXDP]

    xy=max(0,DP[x][y],DP[z][z]+1)
    yz=max(0,DP[y][z],DP[x][x]+1)
    zx=max(0,DP[z][x],DP[y][y]+1)
    
    if x==y:
        for i in range(N+1):
            if DP[i][x]!=-1:
                NLIST.append((i,z,max(DP[i][z],DP[i][x]+1)))
                #DP[i][z]=DP[z][i]=max(DP[i][z],DP[i][x]+1)
         
            NMAXDP[i]=max(NMAXDP[i],DP[i][z],DP[z][i])
            NMAXDP[z]=max(NMAXDP[z],DP[i][z],DP[z][i])

    if y==z:
        for i in range(N+1):
            if DP[i][y]!=-1:
                NLIST.append((i,x,max(DP[i][x],DP[i][y]+1)))
                #DP[i][x]=DP[x][i]=max(DP[i][x],DP[i][y]+1)
                
            NMAXDP[i]=max(NMAXDP[i],DP[i][x],DP[x][i])
            NMAXDP[x]=max(NMAXDP[x],DP[i][x],DP[x][i])

    if z==x:
        for i in range(N+1):
            if DP[i][x]!=-1:
                NLIST.append((i,y,max(DP[i][y],DP[i][x]+1)))
                #DP[i][y]=DP[y][i]=max(DP[i][y],DP[i][x]+1)
                
            NMAXDP[i]=max(NMAXDP[i],DP[i][y],DP[y][i])
            NMAXDP[y]=max(NMAXDP[y],DP[i][y],DP[y][i])

    for i,j,sc in NLIST:
        DP[i][j]=DP[j][i]=max(DP[i][j],sc)
        SCMAX2=max(SCMAX,DP[i][j])

    #for d in DP:
    #    print(*d)
    #print()

    for i in range(N+1):
        DP[i][x]=DP[x][i]=max(DP[i][x],MAXDP[i])
        DP[i][y]=DP[y][i]=max(DP[i][y],MAXDP[i])
        DP[i][z]=DP[z][i]=max(DP[i][z],MAXDP[i])
        SCMAX2=max(SCMAX2,DP[i][x],DP[i][y],DP[i][z])
                   
        NMAXDP[i]=max(NMAXDP[i],DP[i][x],DP[i][y],DP[i][z])
        NMAXDP[x]=max(NMAXDP[x],DP[i][x])
        NMAXDP[y]=max(NMAXDP[y],DP[i][y])
        NMAXDP[z]=max(NMAXDP[z],DP[i][z])

    DP[x][y]=DP[y][x]=max(SCMAX,xy)
    DP[y][z]=DP[z][y]=max(SCMAX,yz)
    DP[z][x]=DP[x][z]=max(SCMAX,zx)
    SCMAX2=max(SCMAX2,DP[x][y],DP[y][z],DP[z][x])

    MAXDP=NMAXDP
    MAXDP[x]=max(MAXDP[x],DP[x][y],DP[y][x],DP[z][x],DP[x][z])
    MAXDP[y]=max(MAXDP[y],DP[x][y],DP[y][x],DP[z][y],DP[y][z])
    MAXDP[z]=max(MAXDP[z],DP[x][z],DP[z][x],DP[z][y],DP[y][z])
    SCMAX=SCMAX2

#for d in DP:
#    print(*d)

DP[D][D]+=1

DPANS=0
for d in DP:
    DPANS=max(max(d),DPANS)

print(ANS+DPANS)