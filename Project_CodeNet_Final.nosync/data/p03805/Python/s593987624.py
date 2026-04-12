from itertools import permutations
n,m=map(int,input().split())
lis=[i for i in range(1,n+1)]
nm=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    nm[a].append(b)
    nm[b].append(a)
count=0
for i in permutations(lis):
    if i[0]==1:
        temp=nm[1]
        for j in range(n-1):
            if not i[j+1] in set(temp):
                break
            temp=nm[i[j+1]]
        else:
            count+=1
print(count)