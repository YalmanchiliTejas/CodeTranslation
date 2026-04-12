import sys
MAX_INT = int(10e15)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N = input()
digit = len(N)
K = I()

# dp[i番目まで][未満かどうか][他の条件]
dp = [[[0]*(K+2) for _ in range(2)] for _ in range(digit+2)]
dp[0][0][0] = 1

for i in range(digit):
  num = int(N[i])
  for j in range(2):
    for k in range(K+2):
      for n in range(9+1 if j else num+1):
        dp[i + 1][j or (n < num)][min(K+1, k + (n != 0))] += dp[i][j][k]
print(dp[digit][0][K] + dp[digit][1][K])