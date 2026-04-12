from itertools import permutations
#N = int(input())
N,M = map(int,input().split())
ab=[[]for i in range(N)]
for i in range(M):
    a,b = list(map(int,input().split()))
    ab[a-1].append(b-1)
    ab[b-1].append(a-1)
num = [i+1 for i in range(N-1)]
count = 0
for i in permutations(num):
    flag = True
    if i[0] not in ab[0]:
        continue
    for j in range(len(i)-1):
        if i[j+1] not in ab[i[j]]:
            flag = False
    if flag:
        count += 1
print(count)