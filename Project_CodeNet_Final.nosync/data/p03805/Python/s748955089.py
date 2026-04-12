from itertools import permutations
n , m = map(int,input().split())
route = [set() for i in range(n+1)]
for i in range(m):
    a , b = map(int,input().split())
    route[a].add(b)
    route[b].add(a)
ans = 0
p=[i + 2 for i in range(n-1)]
kouho = list(permutations(p))

for i in range(len(kouho)):
    now = 1
    flag = True
    for j in kouho[i]:
        if j in route[now]:
            now = j
        else:
            flag = False
            break
    if flag:
        ans += 1
print(ans)