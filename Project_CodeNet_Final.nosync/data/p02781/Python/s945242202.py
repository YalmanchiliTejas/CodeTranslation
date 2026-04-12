N=int(input())
K=int(input())
#桁の数字を取得
dig=[]
n=N
while n>0:
  dig.append(n%10)
  n//=10
a=dig[-1]
digit=len(dig)

dp=[[0 for _ in range(digit)] for _ in range(3)]

dp[0][0]=dig[0]
for i in range(1,digit):
  if dig[i]==0:
    dp[0][i]=dp[0][i-1]
  else:
    dp[0][i]=dig[i]+9*i

for i in range(1,digit):
  if dig[i]==0:
    dp[1][i]=dp[1][i-1]
  else:
    dp[1][i]=dp[0][i-1]+(dig[i]-1)*9*i+81*i*(i-1)//2
    
for i in range(1,digit):
  if dig[i]==0:
    dp[2][i]=dp[2][i-1]
  else:
    dp[2][i]=(dp[1][i-1]  #i桁目がギリギリの場合
              +(dig[i]-1)*81*i*(i-1)//2 #i桁目を使う場合
              +729*i*(i-1)*(i-2)//6) #i桁目を使わない場合
print(dp[K-1][digit-1])