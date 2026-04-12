from itertools import permutations
n,m=map(int,input().split())
adj=[[] for i in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    adj[a].append(b)
    adj[b].append(a)
    
sum=0
for i in permutations(list(range(1,n))):
    i = [0]+list(i)
    c=1
    for j in range(n-1):
        if not(i[j+1] in adj[i[j]]):
            c*=0
    sum+=c
            
print(sum)