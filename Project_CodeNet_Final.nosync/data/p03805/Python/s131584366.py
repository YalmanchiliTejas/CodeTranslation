import itertools

n,m=list(map(int,input().split()))
c=[[] for i in range(n)]

for i in range(m):
    a,b=list(map(int,input().split()))
    c[a-1].append(b-1)
    c[b-1].append(a-1)

cnt=0

for p in itertools.permutations(range(n),n):
    if p[0]>0:
        continue

    for i in range(n-1):
        a=p[i]
        b=p[i+1]

        if not (b in c[a]):
            break
    else:
        cnt+=1

print(cnt)