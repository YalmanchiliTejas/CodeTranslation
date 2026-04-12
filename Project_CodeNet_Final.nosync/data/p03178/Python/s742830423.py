import sys
readline = sys.stdin.readline

S = readline().rstrip()
D = int(readline())
DIV = 10 ** 9 + 7
N = len(S)

dp = [[[0] * D for j in range(2)] for i in range(N)]
# dp[i][smaller][d]

x0 = S[0]
dp[0][0][int(x0) % D] = 1
for i in range(int(x0)):
  dp[0][1][i % D] += 1

last = int(x0) % D
for i in range(1, len(S)):
  x = S[i]
  dp[i][0][(last + int(x)) % D] += dp[i - 1][0][last]
  dp[i][0][(last + int(x)) % D] %= DIV
  
  for j in range(int(x)):
    dp[i][1][(last + j) % D] += dp[i - 1][0][last]
    dp[i][1][(last + j) % D] %= DIV
  
  for j in range(D):
    for k in range(10):
      dp[i][1][(j + k) % D] += dp[i - 1][1][j]
      dp[i][1][(j + k) % D] %= DIV
  last = (last + int(x)) % D
    
print((dp[-1][0][0] + dp[-1][1][0] - 1) % DIV)