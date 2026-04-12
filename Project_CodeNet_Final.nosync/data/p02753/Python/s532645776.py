# 文字列の取得しリストに格納
S = str(input())
S_list = list(S)

# 隣接する文字列を比較し結果を出力
if S_list[0] != S_list[1]\
or S_list[1] != S_list[2]:
  print("Yes")
else:
  print("No")