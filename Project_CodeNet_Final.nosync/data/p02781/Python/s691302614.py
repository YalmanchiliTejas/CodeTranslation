N=input()
K=int(input())
S="0"*(100-len(N))+N
DP=[[[0]*2 for _ in range(K+2)] for _ in range(101)]

DP[0][0][0] = 1
for i in range(100):
  for j in range(K+1):
    #SがN以下かわからないまま、「0」の文字をなぞるとき、0でない数字jはそのまま
    if S[i]=='0':
      DP[i+1][j][0]+=DP[i][j][0]
      
    #SがN以下かわからないまま、「0」以外の文字をなぞるとき、0でない数字jも+1
    else:
      DP[i+1][j+1][0]+=DP[i][j][0]
    
    #SがN以下が確定している　
    DP[i+1][j][1]+= DP[i][j][1]
    if int(S[i])>0:
      #0以外の文字がくると、
      DP[i+1][j][1]+=DP[i][j][0]
      
    #SがN以下が確定しているものは、1~9をくっつけたものと、同じ桁だけどより低い数字が来たとき
    DP[i+1][j+1][1] += DP[i][j][1]*9+DP[i][j][0]*(max(0, int(S[i])-1))
print(sum(DP[-1][K]))