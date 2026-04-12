#! /usr/bin/env python3

import itertools

n, m = map(int, input().split())

dests = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    dests[a-1].append(b-1)
    dests[b-1].append(a-1)

res = 0
p =  list(itertools.permutations(range(n)))

for l in p:
    if l[0] != 0: continue
    flg = True
    for i in range(n-1):
        if not(l[i+1] in dests[l[i]]):
            flg = False
            break

    if flg == True: res += 1

print(res)
