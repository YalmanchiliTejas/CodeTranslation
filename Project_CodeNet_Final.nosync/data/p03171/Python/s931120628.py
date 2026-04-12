import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

from collections import deque

N = int(input())
A = [int(x) for x in input().split()]

"""
・x < M > y → x+y-Mに取り替える
・V字型に帰着
・貪欲

"""

B = deque() # 修正後
for a in A:
    B.append(a)
    while True:
        if len(B) < 3:
            break
        x,y,z = B[-3], B[-2], B[-1]
        if x <= y >= z:
            B.pop()
            B.pop()
            B[-1] = x + z - y
            continue
        break

pts = [0,0]
player = 0
while B:
    if B[0] > B[-1]:
        pts[player] += B[0]
        B.popleft()
    else:
        pts[player] += B[-1]
        B.pop()
    player ^= 1

answer = pts[0] - pts[1]
print(answer)