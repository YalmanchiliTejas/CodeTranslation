A, B, C, X, Y = map(int, input().split())

maxV = max(X, Y)
min_prise = pow(10, 10)

# ABピザの枚数をiとする
for AB_cnt in range(maxV * 2 + 1):
  # Aの金額を計算する
  if X - AB_cnt // 2 > 0:
    A_prise = (X - AB_cnt // 2) * A
  else:
    A_prise = 0

  # Bの金額を計算する
  if Y - AB_cnt // 2 > 0:
    B_prise = (Y - AB_cnt // 2) * B
  else:
    B_prise = 0

  # ABの金額を計算する
  AB_prise = AB_cnt * C

  # A, B, ABの金額を合計する
  sum_prise = A_prise + B_prise + AB_prise

  # sum_priseが最小値よりも小さければ格納する
  if sum_prise < min_prise:
    min_prise = sum_prise

print(min_prise)