from collections import deque
n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
que = deque(a)
right = que.pop()
left = que.popleft()
sums = right - left
while(bool(que)):
  a = que.pop()
  if not bool(que):
    sums += max(abs(right-a),abs(left-a))
    break
  b = que.popleft()
  sums += right + a - left -b
  right = a
  left = b

print(sums)