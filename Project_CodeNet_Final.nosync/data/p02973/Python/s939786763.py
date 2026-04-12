import bisect
from collections import deque
n = int(input())
a = [0 for i in range(n)]
for i in range(n):
    a[i] = int(input())
count = deque()
count.append(a[0])
for i in range(1, n):
    
    index = bisect.bisect_left(count, a[i])
    
    if index == 0:
        count.appendleft(a[i])
    else:
        count[index - 1] = a[i]
    #print("{}  {}".format(count, index))
print(len(count))

