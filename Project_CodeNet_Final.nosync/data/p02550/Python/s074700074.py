import sys

n,x,m=map(int,input().split())

if m==1:
    print(0)
    sys.exit()

check=[-1 for i in range(m)]#which tells position

A=[x%m]
check[x%m]=0

roopstart=10**15
for i in range(1,m):
    Ai=(A[i-1]*A[i-1])%m
    if check[Ai]!=-1:
        roopstart=check[Ai]
        break
    else:
        check[Ai]=i
        A.append(Ai)

if roopstart>=n:
    print(sum(A[:n]))
    sys.exit()

s=sum(A[:roopstart])

nn=n-roopstart
rooplen=len(A)-roopstart
roopnum=nn//rooplen
d=nn%rooplen

roopsum=sum(A[roopstart:])

s+=roopsum*roopnum
s+=sum(A[roopstart:roopstart+d])

print(s)
        
