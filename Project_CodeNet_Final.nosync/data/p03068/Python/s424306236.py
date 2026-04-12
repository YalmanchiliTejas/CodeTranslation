# coding: utf-8
import re
import bisect
from datetime import datetime as dt
N = input()
S = raw_input()
K = input()
a = S[K - 1]
b = ''
for i in range(len(S)):
    if S[i] != a:
        b += '*'
    else:
        b += a
print b
