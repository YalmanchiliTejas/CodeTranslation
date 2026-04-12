import sys
import bisect
from collections import deque

fastinput = sys.stdin.readline
N = int(fastinput())
A = [int(fastinput()) for j in range(N)]
surface = deque([A[0]])#常に小さい順にソートされている
surfMax = A[0]
surfMin = A[0]
color = 1
for n,a in enumerate(A):
    if n==0:continue

    if color == 1:
        c = surface[0]
        if a>c:
            surface[0] = a
            surfMax = a
            surfMin = a
        if a==c:
            surface.appendleft(a)
            color += 1
        if a<c:
            surface.appendleft(a)
            color += 1
            surfMin = a

    else:    
        if a<=surfMin:
            color += 1
            surface.appendleft(a)
            surfMin = a
        elif a>surfMax:
            surface[color-1] = a
            surfMax = a
        else:
            pos = bisect.bisect_left(surface,a) -1 #a未満の最大の整数
            surface[pos] = a
            if pos==0:
                surfMin = a
            if pos == color-1:
                surfMax = a
print(color)
