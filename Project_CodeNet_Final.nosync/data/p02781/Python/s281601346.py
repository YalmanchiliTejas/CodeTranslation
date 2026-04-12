N = int(input())
S = str(N)
m = len(S)
K = int(input())

#dp[i][j][k]: 上からi桁目までに0以外がj個あって、Nと一致しているならばk=0
dp = [[[0] * 2 for _ in range(4)] for _ in range(m+1)]
dp[0][0][0] = 1

for i in range(m): #i=0は架空の桁に相当。
  for j in range(4):
    for k in range(2):
      #dp[i][j][k]という状態が次の桁でどこに遷移するかを考える。遷移先のni,nj,nkを決定する。
      nd = int(S[i]) #Nのi桁目。1桁目はS[0]。
      for d in range(10): #dというのが今の桁(i+1)の値
        ni = i+1 #今の桁
        nj = j
        nk = k
        if d != 0: #もし今の桁が0でなければjは一つ増える。
          nj += 1
        if nj > K: #もしnjが許容値のKを超えたら無視。
          continue
        if k == 0: #ここまで完全一致の時
          if d > nd: #今の桁がNのi桁目より大きいつまりNを超えているので無視。
            continue
          elif d < nd: #今の桁がNのi桁目より小さいなら完全一致ではないのでnk=1と変更。
            nk = 1
        dp[ni][nj][nk] += dp[i][j][k]

ans = dp[m][K][0] + dp[m][K][1]
print(ans)