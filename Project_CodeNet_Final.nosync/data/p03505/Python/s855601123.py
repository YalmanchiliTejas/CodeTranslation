K, A, B = map(int, input().split())

if A >= K:
  print(1)
else:
  if A-B <= 0:
    print(-1)
  else:
    S = -(-(K-A)//(A-B))
    print(S*2+1)