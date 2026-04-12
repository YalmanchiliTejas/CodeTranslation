#!/usr/bin python3
# -*- coding: utf-8 -*-

# ループを検索して計算量圧縮
# 0->1->...->st->st+1->...->st+lp-1-┐
#             └─────────────────────┘
#                       lp

n, x, m = map(int, input().split())

def next(x):
    ret = pow(x,2,m)
    return ret

seen = set([])
seqs = []
for i in range(m+1):
    seen.add(x)
    seqs.append(x)
    x = next(x)
    if x in seen:
        break
start = seqs.index(x)
lp = len(seqs) - start

lpsum = sum(seqs[start:])
lptimes = (n-(start+lp)+(lp-1))//lp
ret_sum = lpsum * lptimes
n -= lp * lptimes
ret_sum += sum(seqs[:n])
ret_val = seqs[n-1]

print(ret_sum)
#print(ret_val)