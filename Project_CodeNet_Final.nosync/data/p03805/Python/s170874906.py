from itertools import permutations
n, m = map(int,input().split())
p =  [[0] * n for i in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    p[a-1][b-1] = 1
    p[b-1][a-1] = 1


l = []
for i in permutations(range(1, n), n-1):
    l.append([0] + list(i))


ans= 0
for i in range(len(l)):
    k = l[i]
    for j in range(n-1):
        if p[k[j]][k[j+1]] != 1:
            break
    else:
        ans += 1

print(ans)



