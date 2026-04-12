import sys
sys.setrecursionlimit(20000)

n, x = map(int, input().split())

sizes = [1] * (n + 1)
nums = [1] * (n + 1)
for i in range(1, (n + 1)):
  sizes[i] = 2 * sizes[i - 1] + 3
  nums[i] = 2 * nums[i - 1] + 1

def f(m, y):
  if m == 0:
    return 1
  if sizes[m] - 1 <= y:
    return nums[m]
  ret = 0
  y -= 1
  if y > 0:
    ret += f(m - 1, min(y, sizes[m - 1]))
    y -= sizes[m - 1]
  if y > 0:
    ret += 1
    y -= 1
  if y > 0:
    ret += f(m - 1, min(y, sizes[m - 1]))
  return ret

print(f(n, x))