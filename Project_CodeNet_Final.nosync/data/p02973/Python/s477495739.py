import bisect

N = int(input())
A = [int(input()) for _ in range(N)]


colors = []
for i in reversed(range(N)):
    if i == N-1:
        colors.append(A[i])
    else:
        if A[i] >= colors[-1]:
            colors.append(A[i])
        # 積む色がある場合
        else:
            idx = bisect.bisect_right(colors, A[i])
            colors[idx] = A[i]


print(len(colors))