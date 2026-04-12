n,k = int(input()),int(input())

l = len(str(n))

s = [0] + list(map(int,str(n))) #n=100の場合[0,1,0,0]みたいな感じ

if k > l:#n=10(l=2)でk=3とかだと該当する整数は存在しない
  print(0)
  exit()

dp = [[[0]*2 for _ in range(k+1)] for _ in range(l+1)]
#[0,0]を要素にもつ, k+1行l+1列の行列
#print(dp)

#dp[][][] の意味はdp[桁][k][0かどうかフラグ]


dp[0][0][1] = 1 #0行0列要素1
#print(dp)

for dig in range(l): #桁
  for i in range(k+1): 
    dp[dig+1][i][0] += dp[dig][i][0]
    dp[dig+1][i][1 if s[dig+1] == 0 else 0] += dp[dig][i][1]
    #sは先頭0, 桁ごとに分けたNのリスト e.g. N=123 -> [0,1,2,3]
    
    if i < k:
      dp[dig+1][i+1][0] += dp[dig][i][0] * 9
      if s[dig+1] > 0:
      	dp[dig+1][i+1][1] += dp[dig][i][1]
      	dp[dig+1][i+1][0] += dp[dig][i][1] * (s[dig+1]-1)

print(dp[l][k][0]+dp[l][k][1])