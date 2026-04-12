import itertools
n,m = map(int,input().split())
mat = [[0]*n for i in range(n)]
for i in range(m):
    u,v = map(int,input().split())
    mat[u-1][v-1] = 1
    mat[v-1][u-1] = 1

cnt = 0
arr = [i for i in range(1,n)]
for road in itertools.permutations(arr):
    start = 0
    for r in road:
        if mat[start][r] ==0:
            break
        else:
            start = r
    else:cnt+=1
print(cnt)
