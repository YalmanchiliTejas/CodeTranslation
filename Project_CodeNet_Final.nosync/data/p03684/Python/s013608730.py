import sys
input=sys.stdin.readline
N=int(input())
P=[tuple(map(int,input().split())) for i in range(N)]
X=[(i,P[i][0]) for i in range(N)]
Y=[(i,P[i][1]) for i in range(N)]
X.sort(key=lambda x:x[1])
Y.sort(key=lambda x:x[1])
Z=[(X[i][0],X[i+1][0],X[i+1][1]-X[i][1]) for i in range(N-1)]+[(Y[i][0],Y[i+1][0],Y[i+1][1]-Y[i][1]) for i in range(N-1)]
Z.sort(key=lambda x:x[2])
root=[-1]*N
def search(i):
    global root
    if root[i]>=0:
        root[i]=search(root[i])
        return root[i]
    return i
ans=0
for i,j,k in Z:
    ri=search(i)
    rj=search(j)
    if ri==rj:
        continue
    elif root[ri]<=root[rj]:
        root[ri]+=root[rj]
        root[rj]=ri
        ans+=k
    else:
        root[rj]+=root[ri]
        root[ri]=rj
        ans+=k
print(ans)