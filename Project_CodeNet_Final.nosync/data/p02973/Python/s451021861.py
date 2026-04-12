import bisect

N = int(input())
A = [int(input()) for _ in range(N)]
M = 10**9
color = []

for i in A:
    tmp = M-i
    if len(color) == 0:
        color.append(tmp)
    elif tmp >= color[-1]:
        color.append(tmp)
    else:
        color[bisect.bisect_right(color, tmp)] = tmp

print(len(color))