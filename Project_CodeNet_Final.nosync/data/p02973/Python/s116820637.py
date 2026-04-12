import bisect
import collections

N = int(input())
A = [int(input()) for _ in range(N)]

ans = collections.deque([A[0]])

for a in A[1:]:
    if a <= ans[0]:  # 色を増やすしかない
        ans.appendleft(a)
    else:  # 既存の色のどこかに追加
        idx = bisect.bisect_left(ans, a)
        ans[idx-1] = a
    # print(a, ans)

# print(ans)
print(len(ans))
