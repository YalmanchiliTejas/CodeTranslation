# -*- coding: utf-8 -*-
import sys 
from collections import defaultdict
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
S = readline().decode()

st = ['SS','SW','WS','WW']

# 8通りの分岐を辞書に登録
d = defaultdict(int)
d['SSo'] = 'S'
d['SSx'] = 'W'
d['SWo'] = 'W'
d['SWx'] = 'S'
d['WSo'] = 'W'
d['WSx'] = 'S'
d['WWo'] = 'S'
d['WWx'] = 'W'
 

#答えの候補をansに代入
ans = []
for s in st:
    t = s  
    for i in range(1,N-1):
        tmp = t[-2:]
        ss = tmp + S[i]
        t += d[ss]
    ans.append(t)

# 答えの候補が矛盾しないかのチェック
for a in ans:
    b = a[N-2]+a[N-1]+S[N-1]
    if d[b] != a[0]:
        continue
    b = a[N-1]+a[0]+S[0]
    if d[b] != a[1]:
        continue
    print(a)
    sys.exit()

print(-1)