import itertools

n,m=map(int, input().split()) 
ab=[list(map(int, input().split())) for _ in range(m)]
#ab=Input.split()
#d：隣接行列

d = [[] for i in range(n)]
for i in range(m):
    a = ab[i][0]
    b = ab[i][1]
    d[a-1].append(b-1)
    d[b-1].append(a-1)
    
#per：順列列挙
per= itertools.permutations(range(1,n))
ans=0
for i in per:
    cnt=1
    x = [0]+list(i)
    for j in range(1,n):
        #隣接していなければ終了
        if not x[j] in d[x[j-1]]:
            break
        else:
            cnt+=1
    if(cnt==n):
        ans+=1
print(ans)
        