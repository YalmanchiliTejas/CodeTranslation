import itertools

n, m = (int(x) for x in input().split())
li = []
for i in range(m):
    li.append([int(x) for x in input().split()])
#print(li)

paths = list(itertools.permutations([int(x) for x in range(1,n+1)]))

#print(paths)

ans = 0
for path in paths:
    if path[0] != 1:
        continue
    flag = True
    for i in range(n-1):
        if path[i] < path[i+1]:
            a = path[i]
            b = path[i+1]
        else:
            b = path[i]
            a = path[i+1]
        if [a,b] not in li:
            flag = False
            break
    if flag:
        ans += 1
print(ans)
