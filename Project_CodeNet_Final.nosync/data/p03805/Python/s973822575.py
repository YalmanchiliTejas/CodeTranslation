import itertools
n,m = list(map(int,input().split()))

a = []
for i in range(m):
    b = (list(map(int,input().split())))
    b = [b[0]-1,b[1]-1]
    a.append(b)

b = [[0 for i in range(n)] for j in range(n)]
for i in a:
    b[i[0]][i[1]] = 1
    b[i[1]][i[0]] = 1


c = [i+1 for i in range(n-1)]
ans = 0
for i in itertools.permutations(c,n-1):
    j = [0]
    j += i
    count = 0
    for i in range(n-1):
        if b[j[i]][j[i+1]] == 1:
            count += 1
            if count == n-1:
                ans += 1
                count = 0
        else:
            break
print(ans)