from collections import deque
import sys
input = sys.stdin.readline
n = int(input())
As = sorted([int(input()) for i in range(n)])
q = deque(As[1:])
# 初期化
ans = 0
cnt = 1
p1 = As[0]
p2 = As[0]
flg = False
while True:
    if len(q) == 0: break
    if flg:
        n1 = q.popleft()
    else:
        n1 = q.pop()
    ans += abs(p1-n1)
    p1 = n1

    if len(q) == 0: break
    if flg:
        n2 = q.popleft()
    else:
        n2 = q.pop()
    ans += abs(p2-n2)
    p2 = n2

    flg = not flg

# 初期化(小さい順)
As = As[::-1]
ans2 = 0
p1 = As[0]
p2 = As[0]
q = deque(As[1:])
flg = False
while True:
    if len(q) == 0: break
    if flg:
        n1 = q.popleft()
    else:
        n1 = q.pop()
    ans2 += abs(p1-n1)
    p1 = n1

    if len(q) == 0: break
    if flg:
        n2 = q.popleft()
    else:
        n2 = q.pop()
    ans2 += abs(p2-n2)
    p2 = n2

    flg = not flg


print(max(ans,ans2))