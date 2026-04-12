from itertools import permutations
n, m = map(int, input().split())
path = []
for i in range(m):
    a, b = map(int, input().split())
    path.append([a,b])
    path.append([b,a])
import itertools
per = [i for i in range(2,n+1)]
data = list(itertools.permutations(per, n-1))  
flg = 0
for k in range(len(data)):
    tmp = [[1, data[k][0]]]
    for i in range(n-2):
        tmp.append([data[k][i],data[k][i+1]])
    cnt = 0
    for var in tmp:
        if var in path:
            cnt += 1
    if cnt == len(tmp):
        flg += 1
print(flg)  