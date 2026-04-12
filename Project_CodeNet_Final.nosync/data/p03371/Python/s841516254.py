A, B, C, X, Y = map(int, input().split())

if (A+B) <= 2*C: # 単品だけで購入
  print(X*A + Y*B)
else:
  # ABを買い残りを単品で補う
  if X >= Y:
    # ABでYは賄える
    print(min(X*2*C, Y*2*C + A*(X-Y)))
  else:
    # ABでXは賄える
    print(min(Y*2*C, X*(2*C)+B*(Y-X)))