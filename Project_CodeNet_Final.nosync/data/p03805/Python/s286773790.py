import itertools

n,m = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(m)]
num = list(range(1,n+1))
ans = 0
for l in itertools.permutations(num):
    if l[0]!=1:
        continue
    flag = True
    for i in range(len(l)-1):
        if not([l[i],l[i+1]] in edges or [l[i+1],l[i]] in edges):
            flag = False
            break
    if flag:
        # print(l)
        ans+=1
print(ans)