n, k = list(map(int, input().split(' ')))
lens = {0: 1}
for i in range(1, 51):
  lens[i] = lens[i-1] * 2 + 3
memo = {}
def sumP(level, index):
  key = (level, index)
  if key in memo:
    return memo[key]
  if level == 0:
    if index == 1:
      memo[key] = 1
    else:
      memo[key] = 0
  elif index < lens[level] // 2 + 1:  # レベル一つ下の奴の一部分のみ
    memo[key] = sumP(level-1, index-1)
  elif index == lens[level] // 2 + 1:  # ど真ん中のPを入れて一つ下全部(index-1は左端のB)
    memo[key] = 1 + sumP(level-1, lens[level-1])
  else: # レベル一つ下の奴の丸々1つ + P + レベル一つ下の奴の一部分もしくは全部, minは最後のBを捨てるため
    memo[key] = sumP(level-1, lens[level-1]) + 1 + sumP(level-1, min(lens[level-1], index-lens[level-1]-2))
  return memo[key]
 
print(sumP(n, k))