# input
N = int(input())
As = list(map(int, input().split()))

# Nの偶奇。区間幅がNの偶奇と一致すれば太郎君目線
oe = N % 2

# def print_list(lis):
#   for l in lis:
#     print(l)


# score[i][j][p] : Asのi番目を左端、j番目を右端とした時の最終スコア
#                  p = 0 が太郎君目線、p = 1 が次郎くん目線
score = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
  # 初期化
  # 区間長さ1であれば1通りしかない
  if oe == 1:
    score[i][i] = As[i]
  else:
    score[i][i] = -As[i]

# print_list(score)

for k in range(1, N):
  # 配列の幅を広げながら計算を進める
  for i in range(0, N-k):
    # if k == 0:
    #   continue
    j = i + k
    if i == N - 1:
      if (k + 1) % 2 == oe:
        score[i][j] = score[i][j-1] + As[j]
      else:
        score[i][j] = score[i][j-1] - As[j]
    else:
      # print(i,j)
      if (k + 1) % 2 == oe:
        score[i][j] = max(score[i+1][j] + As[i], score[i][j-1] + As[j])
      else:
        score[i][j] = min(score[i+1][j] - As[i], score[i][j-1] - As[j])
    # print_list(score)

print(score[0][N-1])
