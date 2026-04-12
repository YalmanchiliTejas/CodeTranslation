import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from collections import deque
from math import ceil

n = int(readline())
a = sorted([int(readline()) for i in range(n)])
c = deque(a[:ceil(n / 2)])
d = deque(a[ceil(n / 2):])
b = deque(a[n // 2:])
a = deque(a[:n // 2])
check_1 = deque([a.popleft()])
check_2 = deque([d.pop()])
for i in range(n // 2):
    if i % 2 == 0:
        check_1.appendleft(b.pop())
        check_2.appendleft(c.popleft())
        if len(b) == 0:
            if len(a) != 0:
                check_1.append(a.popleft())
                check_2.append(d.pop())
            break
        check_1.append(b.pop())
        check_2.append(c.popleft())
    else:
        check_1.appendleft(a.popleft())
        check_2.appendleft(d.pop())
        if len(a) == 0:
            if len(b) != 0:
                check_1.append(b.pop())
                check_2.append(c.popleft())
            break
        check_1.append(a.popleft())
        check_2.append(d.pop())
cnt_1 = 0
cnt_2 = 0
for i in range(1, n):
    cnt_1 += abs(check_1[i - 1] - check_1[i])
    cnt_2 += abs(check_2[i - 1] - check_2[i])
print(max(cnt_1, cnt_2))
