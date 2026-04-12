N, X, M = map(int, input().split())
sup = 10**11
db = [[0]*M for _ in range(sup.bit_length())]
dbcum = [[0]*M for _ in range(sup.bit_length())]
db[0] = [i**2 %M for i in range(M)]
dbcum[0] = [i**2 %M for i in range(M)]
for i in range(1,sup.bit_length()):
  for j in range(M):
    db[i][j] = db[i-1][db[i-1][j]]
    dbcum[i][j] = dbcum[i-1][j]+dbcum[i-1][db[i-1][j]]
ans = X
p = 0
N -= 1
while N:
  if N%2:
    ans += dbcum[p][X]
    X = db[p][X]
  p += 1
  N >>= 1
print(ans)