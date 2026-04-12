import itertools

N, M = map(int, input().split())
node_relationship = [set(map(int, input().split())) for _ in range(M)]
permutations_lis = list(itertools.permutations([x for x in range(1, N + 1)]))
ans = 0

for one_case in permutations_lis:
    if one_case[0] != 1:
        continue

    flg = True
    for i in range(len(one_case) - 1):
        if not flg:
            break
        tmp = {one_case[i], one_case[i + 1]}
        if not tmp in node_relationship:
            flg = False
    if flg:
        ans += 1

print(ans)
