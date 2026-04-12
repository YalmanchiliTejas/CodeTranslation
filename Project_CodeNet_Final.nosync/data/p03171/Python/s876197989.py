N = int(input())
arr = [int(i) for i in input().split()]
tot = sum(arr)
mem = [[0]* N for i in range(N)]
# updating bottom 2 rows
# mem[N-2][j] 
# mem[N-1][N-1]
if N == 1:
  print("%s" % arr[0])
else:
  mem[N-1][N-1] = arr[N-1]
  mem[N-2][N-2] = arr[N-2]
  mem[N-2][N-1] = max(arr[N-2], arr[N-2])

  # updating leftmost cols
  mem[0][0] = arr[0]
  mem[0][1] = max(arr[0], arr[1])
  mem[1][1] = arr[1]

  for i in range(N-3, -1, -1):
    for j in range(i, N):
      if i == 0 and j<=1 or i == 1 and j == 1:
        continue
      val1 = arr[i] + min(mem[i+1][j-1], mem[i+2][j])
      val2 = arr[j] + min(mem[i+1][j-1], mem[i][j-2])
      mem[i][j] = max(val1, val2)
  #print(mem)
  tmp = tot - mem[0][N-1]
  ans = mem[0][N-1] - tmp
  print("%s" % ans)
