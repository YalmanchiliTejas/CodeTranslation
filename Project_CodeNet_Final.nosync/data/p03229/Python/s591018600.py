# https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_c
from collections import deque
n = int(input())
nums = []
for _ in range(n):
    nums.append(int(input()))
nums.sort()
ans = 0
l = 0
r = n - 1
q = deque()
while l <= r:
    left = nums[l]
    right = nums[r]
    if not q:
        ans += abs(right - left)
        q.append(left)
        q.append(right)
        l += 1
        r -= 1
    else:
        s = max(abs(q[-1] - right), abs(q[0] - right))
        t = max(abs(q[-1] - left), abs(q[0] - left))
        if s >= t:
            if abs(q[-1] - right) > abs(q[0] - right):
                ans += abs(q[-1] - right)
                q.append(right)
            else:
                ans += abs(q[0] - right)
                q.appendleft(right)
            r -= 1
        else:
            if abs(q[-1] - left) > abs(q[0] - left):
                ans += abs(q[-1] - left)
                q.append(left)
            else:
                ans += abs(q[0] - left)
                q.appendleft(left)
            l += 1
print(ans)