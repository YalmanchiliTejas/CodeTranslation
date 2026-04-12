H, W = map(int, input().split())
grid = []
count_array = [0] * W
for _ in range(H):
    S = input()
    if '#' in S:
        grid.append(S)
        for i in range(W):
            if S[i] == '.':
                count_array[i] += 1
delete_target = []
for i in range(W):
    if count_array[i] == len(grid):
        delete_target.append(i)
ans = []
for i in grid:
    tmp = ''
    for k in range(W):
        if k in delete_target:
            continue
        tmp += i[k]
    ans.append(tmp)
for i in ans:
    print(i)