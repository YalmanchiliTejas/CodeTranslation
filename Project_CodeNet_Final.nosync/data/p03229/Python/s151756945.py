from collections import deque
import copy
import sys
sys.setrecursionlimit(50000)
N = int(input())
d_1, d_2 = deque([]), deque([])
l = []
for i in range(N):
  l.append(int(input()))
  
l.sort()
l_1, l_2 = copy.copy(l), copy.copy(l)
d_1.append(max(l))
d_2.append(min(l))
l_1.pop()
l_2.pop(0)

def main1(d, l):
  d.appendleft(l[0])
  l.pop(0)
  if l == []:
    return d
  d.append(l[0])
  l.pop(0)
  if l == []:
    return d
  d.appendleft(l[-1])
  l.pop()
  if l == []:
    return d
  d.append(l[-1])
  l.pop()
  if l == []:
    return d
  else:
    return main1(d, l)
  
def main2(d, l):
  d.appendleft(l[-1])
  l.pop()
  if l == []:
    return d
  d.append(l[-1])
  l.pop()
  if l == []:
    return d
  d.appendleft(l[0])
  l.pop(0)
  if l == []:
    return d
  d.append(l[0])
  l.pop(0)
  if l == []:
    return d
  else:
    return main2(d, l)
  
x, y = 0, 0
a = main1(d_1, l_1)
b = main2(d_2, l_2)
for i in range(N-1):
  x += abs(a[i+1]-a[i])
  y += abs(b[i+1]-b[i])
print(max(x, y))