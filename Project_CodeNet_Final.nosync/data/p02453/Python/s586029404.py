import sys
import bisect
input()
arr = list(map(int, input().split()))
nq = int(input())
lines = sys.stdin.readlines()
ans = [None] * nq
for i in range(nq):
    ans[i] = str(bisect.bisect_left(arr, int(lines[i])))
print('\n'.join(ans))
