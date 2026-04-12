#coding: utf-8
import math
import heapq
import bisect
import numpy as np
from collections import Counter, deque
#from scipy.misc import comb

N = int(input())
S = []
for _ in range(N):
    s = input()
    S.append(s)

cnt = [10000]*26
for s in S:
    for i in range(26):
        cnt[i] = min(cnt[i], s.count(chr(97+i)))

ans = ""
for i in range(26):
    if cnt[i] < 10000: ans += chr(97+i)*cnt[i]

print(ans)