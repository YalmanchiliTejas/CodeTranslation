import sys
sys.setrecursionlimit(100000000)

N,X = map(int,input().split())

total_b = [0]
total_p = [1]
total = [1]

for i in range(N):
    b = total_b[-1]*2 + 2
    p = total_p[-1]*2 + 1
    x = b+p
    total_b.append(b)
    total_p.append(p)
    total.append(x)
#print(total,total_b,total_p)

def dfs(x,level):
    if x == 1 or x == 0:
        #print(1)
        return 0
    if x == total[level-1] + 1:
        #print(2)
        return total_p[level-1]
    if x == total[level-1] + 2:
        #print(3)
        return total_p[level-1] + 1
    if x == total[level-1]*2 + 2:
        #print(4)
        return total_p[level-1]*2 + 1
    if x == total[level-1]*2 + 3:
        #print(5)
        return total_p[level-1]*2 + 1
    if x > 1 and total[level-1] + 1 > x:
        #print(6)
        return dfs(x-1,level-1)
    if x > total[level-1] + 2 and total[level-1]*2 + 2 > x:
        #print(7)
        return dfs(x - total[level-1] - 2,level-1) + total_p[level-1] + 1
ans = dfs(X,N)
print(ans)