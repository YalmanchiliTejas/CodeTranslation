from bisect import bisect_left
N = int(input())
memo = [-1]*N
for _ in range(N):
    a = int(input())
    idx = bisect_left(memo,a)-1
    memo[idx] = a

print(N-memo.count(-1))