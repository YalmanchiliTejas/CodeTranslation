num = [1]
for i in range(1, 50):
  num.append(2 * num[i - 1] + 3)
def count_p(level, x):
  if x == 0:
    return 0
  if level == 1:
    if x == 5:
      return 3
    else:
      return x - 1
  if x < num[level - 1] + 1:
    return count_p(level - 1, x - 1)
  if x == num[level - 1] + 1:
    return 2 ** level - 1
  if x >= num[level - 1] * 2 + 2:
    return 2 ** (level + 1) - 1
  if x >= num[level - 1] + 2:
    return 2 ** level + count_p(level - 1, x - num[level - 1] - 2)


N, X = map(int, input().split())
print(count_p(N, X))