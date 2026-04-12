import sys
def ii(): return int(sys.stdin.readline())
def mi(): return map(int, sys.stdin.readline().split())
def li(): return list(map(int, sys.stdin.readline().split()))
def li2(N): return [list(map(int, sys.stdin.readline().split())) for i in range(N)]
def dp2(ini, i, j): return [[ini]*i for i2 in range(j)]
def dp3(ini, i, j, k): return [[[ini]*i for i2 in range(j)] for i3 in range(k)]
#import bisect #bisect.bisect_left(B, a)
#from collections import defaultdict #d = defaultdict(int) d[key] += value

N = ii()
A = sorted([ii() for _ in range(N)])

if N % 2:
    ans_1 = sum(A[N//2+1:])*2 - sum(A[:N//2+1])*2
    ans_1 += A[N//2-1] + A[N//2]
    ans_2 = sum(A[N//2:])*2 - sum(A[:N//2])*2
    ans_2 -= A[N//2] + A[N//2+1]
    print(max(ans_1, ans_2))
else:
    ans = sum(A[N//2:])*2 - sum(A[:N//2])*2
    ans -= A[N//2] - A[N//2-1]
    print(ans)