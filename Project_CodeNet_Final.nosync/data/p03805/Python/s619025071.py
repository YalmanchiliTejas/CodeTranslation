from collections import deque

N, M = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(M)]

# n!通りの全探索?

"""
- 頂点起点で見る
     - 全パターン書き出す
- 辺起点で見る
"""
ans = deque([[1]])

while ans:
    a = ans.popleft()
    for i in range(2, N + 1):
        if i not in a:
            ans.append(a + [i])
    if len(ans[0]) == N:
        break

cnt = 0

for a in ans:
    tmp_cnt = 0
    for i in range(len(a) - 1):
        if [a[i], a[i + 1]] in AB or [a[i + 1], a[i]] in AB:
            tmp_cnt += 1
            continue
        else:
            break
    if tmp_cnt == len(a) - 1:
        cnt += 1

print(cnt)