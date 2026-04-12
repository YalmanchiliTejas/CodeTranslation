import bisect

N = int(input())

A = [int(input()) for _ in range(N)]

colors = []

for i in range(N-1, -1, -1):
    target = bisect.bisect_right(colors, A[i])

    if target == len(colors):
        colors.append(A[i])
    else:
        colors[target] = A[i]

print(len(colors))
