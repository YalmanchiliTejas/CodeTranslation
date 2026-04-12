import itertools
N, M = map(int, input().split())
p=[[0]*N for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    p[a-1][b-1]=1
    p[b-1][a-1]=1
cnt=0
a=[i for i in range(N)]

for i in itertools.permutations(a):
    flag=0
    if i[0]==0:
        for j in range(1,N):
            if p[i[j]][i[j-1]]!=1:
                flag=1
        if flag==0:
            cnt+=1
    
print(cnt)
      