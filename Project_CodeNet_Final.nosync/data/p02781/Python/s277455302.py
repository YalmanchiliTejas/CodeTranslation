
N = int(input())
K = int(input())


def nCr(n,r):
  if n < 0 or r < 0 or n < r: return 0
  if n - r < r: r = n - r
  if r == 0: return 1
  if r == 1: return n
  
  # 分子のn*(n-1)*...がr個分続くやつ
  numerator = [n-r+k+1 for k in range(r)]
  # 分母：r!=r*(r-1)*...*3*2の要素
  denominator = [k+1 for k in range(r)]
  
  # 分母の要素で割れる部分を割っていく部分
  for p in range(2, r+1):
    # 分母は1,2,3,...rのようになっており、1は意味がないのでスキップした形か
    pivot = denominator[p-1]
    if pivot > 1:
      # 分子のX番目と分母のX-offset番目が共通の約数を持つということだと思う。piv分ずれているのだから、pivの倍数というところか
      offset = (n-r) % p
      for k in range(p-1, r, p):
        # 約分できる要素について割る
        numerator[k - offset]  /= pivot
        denominator[k] /= pivot
        
  ret = 1
  for k in range(r):
    if numerator[k] > 1: ret *= int(numerator[k])
      
  return ret


dp = [[[0 for _ in range(2)] for _ in range(K+1)] for _ in range(len(str(N))+1)]
# 頭から0桁目まで決めて、0以外の数が0個既に使われている時、i桁目までの部分がNより小さいのは0の一通り
dp[0][0][0] = 1


for i in range(len(str(N))):
    digit = int(str(N)[i])
    for j in range(K+1):
        # i桁目までがNのそこまでより小さい場合、i-1桁目までもNのi-1桁目までより小さいことが確定するから、
        # i-1 -> iへの派生を入れる（from 厳密に小さい to 厳密に小さい）
        dp[i+1][j][1] += dp[i][j][1]

        # i-1桁目までがNのi-1桁目までより小さくなく（一致し）、Nのi桁目が０であれば、作っている数字のi桁目が０になる
        if digit == 0:
            # 厳密に小さくされないので（from 厳密に小さくない to 厳密に小さくない）
            dp[i+1][j][0] += dp[i][j][0]
        else:
            """
            314159で、31OXXXかつNの3桁目までより小さいパターンは、31XXXXから派生
            """
            # （from 厳密に小さくない（一致する） to 厳密に小さい）
            dp[i+1][j][1] += dp[i][j][0]
        
        # 先頭になんか0以外の数字を入れて、残りがまだ0以外の数字を入れる必要があるとき
        if j-1 >= 0:
            # 0以外のなんかの値を使ったので j-1 -> j かつ  * 9（０以外をいれる）
            dp[i+1][j][1] += dp[i][j-1][1] * 9
            if digit != 0:
                # i桁目が一致する（Nのiまでより小さくならない）パターンについて、直前の場合の数を足す
                dp[i+1][j][0] += dp[i][j-1][0]
                # i桁目までが、Nのそれまでより小さくなるパターンについて、i桁目ではdより小さい値をとれる
                dp[i+1][j][1] += dp[i][j-1][0] * (digit-1)

print(sum(dp[-1][-1]))