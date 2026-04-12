import sys
input = sys.stdin.readline

import numpy as np

N = int(input())
A = np.array(input().split(), dtype=np.int64)

def test(T):
    # T回操作をやるとして上手くいくか
    # ひとつひとつの数は、何もしないとa + T になってしまう
    # 1回やるとそこから N+1 減る。最低回数が分かる。
    # (a + T - N + 1) / (N+1) の切り上げ
    # (a + T + 1) // (N+1)
    x = np.maximum(0, (A + T + 1) // (N + 1))
    return x.sum() <= T

# とりあえずひとつ見つける
left = -1
right = 10 ** 18
while right > left + 1:
    mid = (left + right) // 2
    if test(mid):
        right = mid
    else:
        left = mid

for x in range(max(0, right - 5000), right + 1):
    if test(x):
        answer = x
        break

print(answer)