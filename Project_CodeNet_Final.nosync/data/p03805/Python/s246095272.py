from collections import defaultdict

n, m = map(int, (input().split()))
dic = defaultdict(list)
seen = [False] * (n+1)
count = 0

for _ in range(m):
    a, b = map(int, input().split())
    dic[a].append(b)
    dic[b].append(a)


def dfs(pos, pre_pos, depth, seen):
    if seen[pos]:
        return

    seen[pos] = True
    todo = dic[pos]

    for next_pos in todo:
        if next_pos == pre_pos:
            continue
        dfs(next_pos, pos, depth+1, seen)

    seen[pos] = False
    if depth == n:
        global count
        count += 1
    return


dfs(1, -1, 1, seen)
print(count)