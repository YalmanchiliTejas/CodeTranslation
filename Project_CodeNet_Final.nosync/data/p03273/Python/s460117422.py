import sys
import numpy as np

rm = lambda: map(int, sys.stdin.readline().split())
rr = lambda: sys.stdin.readline().rstrip()

h, w = rm()
li = np.array([np.array(list(rr())) for _ in range(h)])
li2 = []
li3 = []
for i in li:
  if '#' in i:
    li2.append(i)
li2 = np.array(li2).T
for i in li2:
  if '#' in i:
    li3.append(i)
li3 = np.array(li3).T
for i in li3:
  print(''.join(i))
