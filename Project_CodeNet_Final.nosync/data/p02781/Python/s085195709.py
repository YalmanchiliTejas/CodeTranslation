from itertools import product

dp = [[[0 for k in range(2)] for j in range(5)] for i in range(105)]

s = input()
n = len(s)
K = int(input())

#i:桁
#j:ゼロ以外の数
#k:上限フラグ
dp[0][0][0] = 1

for i, j, k in product(range(n), range(0,4),(0,1)):
  nd=int(s[i])
#  print(i,j,k)
  for d in range(0,10):
    ni,nj,nk=i+1,j,k
    #ゼロ以外だったらjをカウントアップ
    if d!=0:
      nj+=1
    #jがKより大きくなったらスキップ
    if nj>K:
      continue
    #ここまでの桁が上限に達している場合
    if k==0:
    #上限の桁を超えた場合スキップ
      if d>nd:
        continue
    #この桁は上限未満
      elif d<nd:
        nk=1
#    print(i,j,k,ni,nj,nk)
    dp[ni][nj][nk]+=dp[i][j][k]
#    print(dp[ni][nj][nk])
print(dp[n][K][0]+dp[n][K][1])