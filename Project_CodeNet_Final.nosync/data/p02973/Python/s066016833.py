#E
from collections import deque
import bisect
n = int(input())
a = [int(input()) for _ in range(n)]
result = deque()

for i in a:
    idx = bisect.bisect_left(result,i)
    if idx == 0:
        result.appendleft(i)
        
    else:
        result[idx-1] = i
        
print(len(result))
        