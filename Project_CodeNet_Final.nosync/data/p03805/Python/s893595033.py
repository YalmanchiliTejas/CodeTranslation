import itertools

n, m = list(map(int, input().split()))

ab_list = []

for _ in range(0, m):
    a, b = list(map(int, input().split()))
    ab_list.append((a, b))
    ab_list.append((b, a))

# 全探索で解く場合
l = range(1, n+1)
count = 0
roots = [v for v in itertools.permutations(l, n) if v[0] == 1]

for v in roots:
    is_ok = True
    for i, _ in enumerate(list(v)[:-1]):
        # 探索対象となるエッジ
        target_edge = (list(v)[i], list(v)[i+1])
        if (target_edge not in ab_list):
            is_ok = False

    if is_ok:
        count += 1

print(count)
