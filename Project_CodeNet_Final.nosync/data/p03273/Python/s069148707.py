import numpy as np
h,w = map(int,input().split())
s = []
for i in range(h):
    tmp = list(input())
    if len(set(tmp)) == 1 and tmp[0] == '.':
        continue
    s.append(tmp)
ss = np.array(s).T
ans1 = []
si = ss.tolist()

for i, w in enumerate(si):
    if len(set(w)) == 1 and w[0] == '.':
        continue
    else:
        ans1.append(w)
ans = np.array(ans1).T.tolist()

for i, w in enumerate(ans):
    print(''.join(w))
    
