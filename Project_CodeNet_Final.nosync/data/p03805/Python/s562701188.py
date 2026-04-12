import itertools
import math

n, m = [int(i) for i in input().split()]
town = [[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(m):
    a, b = [int(i) for i in input().split()]
    town[a][b] = 1
    town[b][a] = 1

lis =[i for i in range(1,n+1)]
permutations_lis = itertools.permutations(lis)

count = 0
for one_case in permutations_lis:
    if (one_case[0] == 1):
        flag = 1
    else:
        flag = 0

    for i in range(n-1):
        if(town[one_case[i]][one_case[i+1]] == 0):
            flag = 0
    if(flag == 1):
        count += 1

print(count)