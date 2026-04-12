import bisect
from collections import deque
n = int(input())
a = [int(input()) for _ in range(n)]
tree = deque([]) 
tree.append(a[0])

for a in a[1:]:
  index = bisect.bisect_left(tree, a)
  if index == 0:
    tree.appendleft(a)
  else:
    tree[index-1] = a
print(len(tree))

    


    
    