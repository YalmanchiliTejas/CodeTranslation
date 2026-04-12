N, X = map(int, input().split())

layer_size = [1]
P_cnt = [1]

for _ in range(50):
  #[-1]は末尾の要素を取得。layer_sizeで、合計
  layer_size.append(layer_size[-1]*2+3)

  #[-1]は末尾の要素を取得。P_cntはパティの枚数
  P_cnt.append(P_cnt[-1]*2+1)


def solve(level, x):
  if x == 1:
    return 0 if level > 0 else 1
  l = layer_size[level-1]
  p = P_cnt[level-1]
  if x <= 1+l:
    return solve(level-1, x-1)
  elif x == l+2:
    return p+1
  elif x <= 2*l+2:
    return p+1+solve(level-1, x-l-2)
  else:
    return 2*p+1
  
ans = solve(N, X)
print(ans)