#import sys
#print(sys.maxsize)
N,X,M=map(int,input().split())
#table=list(range(M))
#for i in range(M):
 #   table[i]=((table[i]%M)**2)%M
#print(table[471])
start=X%M
rset=set()
rireki=list()
rset.add(start)
rireki.append(start)
ss=0
for j in range(1,M+1):
    start=(start**2)%M
    if start in rset:
        ss=rireki.index(start)
        break
    else:
        rireki.append(start)
        rset.add(start)
nn=len(rireki)
rep=(N-ss)//(nn-ss)
nokori=N-ss-rep*(nn-ss)
loop=rireki[ss:]
#print(nn)
#print(rep)
#print(sum(loop))
#print(ss)
#print(nokori+rep*(nn-ss)+ss)
if 0 in rireki:
    goukei=sum(rireki)
else:
    goukei=rep*sum(loop)+sum(rireki[:ss])+sum(loop[:nokori])
print(goukei)