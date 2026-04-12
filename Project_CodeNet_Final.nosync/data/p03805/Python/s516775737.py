import copy

def perm(i, ls):
    if not ls:
        return 1
    else:
        count = 0
        for j in ls:
            if cost[i-1][j-1]:
                ls2 = copy.copy(ls)
                ls2.remove(j)
                count += perm(j, ls2)
        return count

n,m = map(int, input().split())

cost = [[0 for _ in range(n)] for _ in range(n)]
for i in range(m):
    a, b= map(int, input().split())
    cost[a-1][b-1] = cost[b-1][a-1] = 1


count = perm(1, list(range(2, n+1)))

print(count)