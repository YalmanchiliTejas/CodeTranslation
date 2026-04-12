import sys
from pprint import pprint

import itertools

n, m = map(int, sys.stdin.readline().strip().split(" "))

edges = set()
for _ in range(m):
    a, b = map(int, sys.stdin.readline().strip().split(" "))
    edges.add((a, b))
    edges.add((b, a))

ans = 0
for seq in itertools.permutations([i for i in range(1,n+1)]):
    # pprint(seq)
    flag = True
    for i in range(n-1):
        # print(seq[i], seq[i+1])
        if i == 0 and seq[i] != 1:
            # print("Not start from 1")
            flag = False
            break
        if (seq[i], seq[i+1]) not in edges:
            # print("Not")
            flag = False
            break
    if flag:
        ans += 1

print(ans)