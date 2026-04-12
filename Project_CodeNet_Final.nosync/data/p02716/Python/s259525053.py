N = int(input())
A = list(map(int, input().split()))

if N % 2 == 0:#Nが偶数
  inf = float("inf")
  DP = [[-inf for i in range(2)] for i in range(N)]
  #print(DP)
  DP[0][0] = A[0]
  DP[1][1] = A[1]
  for i in range(2, N):
    DP[i][0] = DP[i - 2][0] + A[i]
    DP[i][1] = max(DP[i - 2][1], DP[i - 3][0]) + A[i]
  print(max(DP[N - 2][0], DP[N - 1][1]))
  
else:#Nが奇数         
  #print(N)
  inf = float("inf")
  DP = [[-inf for i in range(3)] for i in range(N)]
  #print(DP)
  DP[0][0] = A[0]
  DP[1][1] = A[1]
  DP[2][2] = A[2]
  DP[2][0] = A[0] + A[2]
  for i in range(3, N):
    DP[i][0] = DP[i - 2][0] + A[i]
    DP[i][1] = max(DP[i - 2][1], DP[i - 3][0]) + A[i]
    DP[i][2] = max(DP[i - 2][2], DP[i - 3][1]) + A[i]
  print(max(DP[N - 2][1], DP[N - 1][2]))
  

  