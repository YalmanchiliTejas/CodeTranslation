n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

routes = [[] for _ in range(n)]
for i in range(m):
    routes[ab[i][0]-1].append(ab[i][1]-1)
    routes[ab[i][1]-1].append(ab[i][0]-1)

options = [i for i in range(n)]

combinations = ["0"]
for k in range(n-1):
    combinations = [i+str(j) for j in options for i in combinations if str(j) not in i]

allcount = 0
for i in range(len(combinations)):
    for j in range(n-1):
        if int(combinations[i][j+1]) not in routes[int(combinations[i][j])]:
            break
    else:
        allcount+=1

print(allcount)