import bisect
import sys
input = sys.stdin.readline

N = int(input())
L = [-1 * int(input())]
for _ in range(N - 1):
    a = -1 * int(input())
    if a >= L[-1]:
        L.append(a)
        continue

    i = bisect.bisect_right(L, a)
    L[i] = a

print(len(L))