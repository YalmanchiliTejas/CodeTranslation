N_str=input()
K=int(input())

#print(N_str)
digit_N=len(N_str)

#dp[i][j]: j:digit, k:K
dp_eq=[]
dp_ne=[]
for i in range(digit_N):
  dp_eq.append([0]*(K+1))
  dp_ne.append([0]*(K+1))

#init
dp_eq[0][1]=1
dp_ne[0][1]=int(N_str[0])-1
for i in range(digit_N):
  dp_ne[i][0]=1

for j in range(1,digit_N):
  digit=int(N_str[j])
  for k in range(1,K+1):
    if digit==0:
      dp_ne[j][k]=dp_ne[j-1][k]+9*dp_ne[j-1][k-1]
      dp_eq[j][k]=dp_eq[j-1][k]
    else:
      dp_ne[j][k]=dp_ne[j-1][k]+9*dp_ne[j-1][k-1]+dp_eq[j-1][k]+(digit-1)*dp_eq[j-1][k-1]
      dp_eq[j][k]=dp_eq[j-1][k-1]
    
print(dp_ne[-1][K]+dp_eq[-1][K])