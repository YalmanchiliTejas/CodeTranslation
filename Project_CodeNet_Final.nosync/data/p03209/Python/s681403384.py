from collections import defaultdict


def burger(lv, x):
    if d[(lv, x)] >= 0:
        return d[(lv, x)]

    if x < 1 or x > cnt[lv]:
        d[(lv, x)] = 0
        return d[(lv, x)]

    # base case
    if (lv, x) == (0, 1):
        d[(lv, x)] = 1
        return d[(lv, x)]

    half = (cnt[lv] - 1) // 2
    if x <= half:
        d[(lv, x)] = burger(lv - 1, x - 1)
        return d[(lv, x)]
    else:
        d[(lv, x)] = burger(lv - 1, half - 1) + 1 + burger(lv - 1, min(x - 1 - half, half - 1))
        return d[(lv, x)]


n, x = map(int, input().split())
cnt = [1]
for lv in range(1, 50 + 1):
    cnt.append(cnt[-1] * 2 + 3)
d = defaultdict(lambda: -1)

print(burger(n, x))
# print(d)
