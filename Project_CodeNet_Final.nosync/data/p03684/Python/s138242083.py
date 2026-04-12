N=int(input())
import sys
input=sys.stdin.readline
X=[(-10**10,0)]
Y=[(-10**10,0)]

for i in range(N):
    x,y=map(int,input().split())
    X.append((x,i+1))
    Y.append((y,i+1))
X.append((10**10,N+1))
Y.append((10**10,N+1))
X.sort()
Y.sort()

#print(X,Y)

L=[[]for i in range(N+1)]
for i in range(1,N+1):
    L[X[i][1]].append((X[i][0]-X[i-1][0],X[i-1][1]))
    L[X[i][1]].append((X[i+1][0]-X[i][0],X[i+1][1]))
for i in range(1,N+1):
    L[Y[i][1]].append((Y[i][0]-Y[i-1][0],Y[i-1][1]))
    L[Y[i][1]].append((Y[i+1][0]-Y[i][0],Y[i+1][1]))
#print(L)
C=[1 for i in range(N+2)]
C[0]=0
C[-1]=0
C[1]=0
import heapq
ans=0
Q=L[1]
heapq.heapify(Q)
for i in range(10**6):
    #print(ans,Q)
    #print(C)
    if len(Q)==0:
        break
    q=heapq.heappop(Q)
    if C[q[1]]==0:
        continue
    else:
        C[q[1]]=0
        ans+=q[0]
        for j in range(4):
            if C[L[q[1]][j][1]]==1:
                heapq.heappush(Q,L[q[1]][j])
print(ans)