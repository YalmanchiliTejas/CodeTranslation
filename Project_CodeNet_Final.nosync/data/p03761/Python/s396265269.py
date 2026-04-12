# https://atcoder.jp/contests/abc058/tasks/arc071_a
# C - 怪文書 / Dubious Document
import collections

n = int(input().split()[0])
s_list = []

for _ in range(n):
    s = input().split()[0]
    s_list.append(s)

# 何の文字が最低何個必要か
c_list = []
c_dict = {}

for s in s_list:
    c = collections.Counter(s)
    c_list.append(c)

common_k_list = list(c_list[0].keys())

for c in c_list[1:]:
    for c_k in common_k_list:
        if c_k not in c.keys():
            common_k_list.remove(c_k)

c_dict = {k: float('inf') for k in common_k_list}

for c in c_list:
    for k in common_k_list:
        c_dict[k] = min(c_dict[k], c[k])

ans = ''.join([k * v for k, v in c_dict.items()])

# 辞書順最小を作る
ans = ''.join(sorted([k * v for k, v in c_dict.items()]))
print(ans)
