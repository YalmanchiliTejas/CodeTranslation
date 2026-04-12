import itertools
N,M=map(int,input().split())
path=[list(map(int,input().split())) for _ in range(M)]
seq=list(range(2,N+1))
#print(path)
l=list(itertools.permutations(seq))
#print(l)
buf=[]
cnt=0
for i in range(len(l)):
    buf=list(l[i])
    piv1=1
    #print(buf,len(buf))
    for j in range(len(buf)):
        flag = 0
        piv2=buf[j]
        #print(i,piv1,piv2)
        for k in range(M):
            mi=min(piv1,piv2)
            ma=max(piv1,piv2)
            if (path[k][0]==mi)and(path[k][1]==ma):
                flag=1
        #input()
        if flag==0:
            break
        else:
            piv1=piv2
    if flag==1:
        cnt=cnt+1
print(cnt)



