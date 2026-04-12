import numpy as np
H, W = map(int, input().split())
a = []
for i in range(H):
  s = str(input())
  l = [c for c in s]
  a.append(l)
  
a = np.array(a)
cnt = 0
for i in range(H):
  s = np.array([a[0]])
  a = np.delete(a, 0, 0)
  if '#' in s:
    a = np.append(a, s, axis=0)
    cnt += 1
    
for i in range(W):
  s = np.array([a[:, 0]]).reshape(cnt, 1)
  a = np.delete(a, 0, 1)
  if '#' in s:
    a = np.append(a, s, axis=1)

for ans in a:
  print(''.join(ans))