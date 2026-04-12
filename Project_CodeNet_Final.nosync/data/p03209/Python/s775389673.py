n, k = list(map(int, input().split(' ')))
#l = {}
#l[0] = 'P'
#def f(index):
#  return l[index] if index in l else 'B' + f(index-1) + 'P' + f(index-1) + 'B'
# print(f(50)) dead
    #P
   #BPPPB
  #BBPPPBPBPPPBB
 #BBBPPPBPBPPPBBPBBPPPBPBPPPBBB
#BBBBPPPBPBPPPBBPBBPPPBPBPPPBBBPBBBPPPBPBPPPBBPBBPPPBPBPPPBBBB
# length(x) = 2 * length(x-1) + 3
lens = {}
lens[0] = 0
lens[1] = 1
for i in range(2,52):
  lens[i] = lens[i-1] * 2 + 3
memo = {}
def sumP(level, index):
  key = (level, index)
  if key in memo:
    return memo[key]
  if level <= 0 or index <= 0:
    memo[key] = 0
  elif level == 1 and index == 1:
    memo[key] = 1
  elif index == lens[level] // 2 + 1:  # ど真ん中のPを入れて一つ下全部(index-1は左端のB)
    memo[key] = 1 + sumP(level-1, index-1)
  elif index < lens[level] // 2 + 1:  # レベル一つ下の奴の一部分のみ
    memo[key] = sumP(level-1, index-1)
  else: # レベル一つ下の奴の丸々1つ + P + レベル一つ下の奴の一部分もしくは全部
    memo[key] = sumP(level-1, lens[level-1]) + 1 + sumP(level-1, index-lens[level-1]-2)
  return memo[key]
print(sumP(n+1, k))  # level 1ずれてる！

#BBPPPBPBPPPBB = 13 

  