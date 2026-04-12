# AtCoder Beginner Contest 134 E - Sequence Decomposing

import sys
import bisect

N = int(input())
now = int(sys.stdin.readline().strip())
ans = [now]

for n in range(N - 1):
    now = int(sys.stdin.readline().strip())

    if now > ans[0]:
        ans[0] = now
    elif ans[-1] >= now:
        ans.append(now)
    else:
        # 2部探査で行進位置を探る
        left = 0  # 挿入不可能
        right = len(ans) - 1  # 挿入可能

        while right - left > 1:
            mid = (right + left) // 2
            if now > ans[mid]:
                right = mid
            else:
                left = mid

        ans[right] = now

print(len(ans))

    # if ans:  # 最初の入力以外であり、すでに追加対象のリストが存在する
    #     if ans[0][-1] < now:
    #         ans[0].append(now)
    #     elif ans[-1][-1] >= now:
    #         appending = [now]
    #         ans.append(appending)
    #     else:
    #         # 二分探索で追加するリストの位置を特定する
    #         left = 0   # 追加できない  ans[left][-1] > now
    #         right = len(ans) - 1  # ans[right][-1] < now
    #
    #         while right - left > 1:
    #             mid = (right - left) // 2
    #             if ans[mid][-1] < now:
    #                 right = mid
    #             else:
    #                 left = mid
    #         ans[right].append(now)
    # else:
    #     appending = [now]
    #     ans.append(appending)

    # for a in ans:
    #     if a[-1] < now:
    #         a.append(now)
    #         break
    # else:
    #     appending = [now]
    #     ans.append(appending)

# print(len(ans))
