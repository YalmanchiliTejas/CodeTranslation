import itertools

count = 0
N, M = map(int, input().split())
listN = [i for i in range(2, N + 1, 1)]
listM = []
for j in range(M):
    new_keiro = list(map(int, input().split()))
    listM.append(new_keiro)
    listM.append(new_keiro[::-1])

all_listN = list(itertools.permutations(listN))

for now_listN in all_listN:
    judge = True
    if [1 ,now_listN[0]] in listM:
        x = 0
    else:
        judge = False
    for k in range(len(now_listN) - 1):
        if [now_listN[k],now_listN[k + 1]] in listM:
            x = 0
        else:
            judge = False
    count += judge

print(count)