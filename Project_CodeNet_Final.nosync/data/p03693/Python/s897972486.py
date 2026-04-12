S = list(map(str, input().split()))
S = int(S[0] + S[1] + S[2])

if S%4 == 0:
  print('YES')
else:
  print('NO')
