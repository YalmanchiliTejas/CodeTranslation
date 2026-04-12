getS = lambda: input().strip()
getN = lambda: int(input())
getList = lambda: list(map(int, input().split()))
getZList = lambda: [int(x) - 1 for x in input().split()]
n, m = getList()
if n == m:
  print("Yes")
else:
  print("No")