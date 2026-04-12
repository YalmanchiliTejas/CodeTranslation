from collections import deque
import bisect
import sys
input = sys.stdin.readline


n = int(input())
color_box = deque([-1])

for _ in range(n):
    num = int(input())
    idx = bisect.bisect_left(color_box, num)
    if idx == 0:
        color_box.appendleft(num)
    else:
        color_box[idx-1] = num

print(len(color_box))