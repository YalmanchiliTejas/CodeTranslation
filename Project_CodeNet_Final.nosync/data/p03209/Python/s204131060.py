n, k = list(map(int, input().split(' ')))
lens = {0: 1}
for i in range(1, 51):
  lens[i] = lens[i-1] * 2 + 3

memo = {}
def sumP(level, index):
  key = (level, index)
  if key in memo:
    return memo[key]
  if level == 0:                       # |P or P|
      memo[key] = int(index == 1)
  elif index < lens[level] // 2 + 1:   # |Bxxxxxxx|xxxxxPxxxxxxxxxxB
    memo[key] = sumP(level-1, index-1)
  elif index <= lens[level] // 2 + 1:  # |BxxxxxxxxxxxxP|xxxxxxxxxxB
    memo[key] = 1 + sumP(level-1, lens[level-1])
  else:                                # |BxxxxxxxxxxxxPxxxxxxxx|xxB
    memo[key] = sumP(level-1, lens[level-1]) + 1 + sumP(level-1, min(lens[level-1], index-lens[level-1]-2))
  return memo[key]

print(sumP(n, k))