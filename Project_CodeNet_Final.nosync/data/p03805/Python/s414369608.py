import itertools

n,m = map(int,input().split())

v = list(range(1,n+1))

edge = []
for i in range(m):
    a,b = map(int,input().split())
    edge.append((a,b))
    edge.append((b,a))
res = 0
for s in itertools.permutations(v):
    if s[0]!=1:
        continue
    flag = True
    for i in range(1,len(s)):
        if (s[i-1],s[i]) not in edge:
            flag =False
    if flag:
        res+=1   
print(res)
