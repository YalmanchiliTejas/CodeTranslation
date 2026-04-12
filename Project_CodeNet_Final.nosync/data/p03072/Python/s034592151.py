import numpy as np

n = int(input())
h = np.array([
  int(i) for i in input().split()])

highest = np.array(
  [max(h[:i]) if i>0 else 0
   for i in range(len(h))])

print(np.sum(h>= highest))