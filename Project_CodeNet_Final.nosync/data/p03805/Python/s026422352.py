import itertools

n, m = map(int, input().split())
AB = []
for i in range(m):
    AB.append(list(map(int, input().split())))
ct = 0
N_lis = [(i + 2) for i in range(n - 1)]
Pat = itertools.permutations(N_lis)
for one_case in Pat:
    tmp = 1
    all_flag = True
    for j in one_case:
        flag = False
        for k in range(m):
            if AB[k][0] == tmp:
                if AB[k][1] == j:
                    tmp = j
                    flag = True
                    break
            elif AB[k][1] == tmp:
                if AB[k][0] == j:
                    tmp = j
                    flag = True
                    break
        if not flag:
            all_flag = False
            break
    if all_flag:
        ct += 1
print(ct)