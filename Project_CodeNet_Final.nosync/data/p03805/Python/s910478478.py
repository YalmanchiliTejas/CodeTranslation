from itertools import permutations
n,m = map(int,input().split())

li = set()
for i in range(m):
    a,b = map(int,input().split())
    li.add((a,b))
    li.add((b,a))

#print(li)
ans = 0

for v in permutations(range(1,n+1)):
    if v[0] != 1:
        continue
    flag = True
    for i in range(len(v)-1):
        if (v[i],v[i+1]) not in li:
            flag = False
            break
    if flag:
        ans +=1
print(ans)