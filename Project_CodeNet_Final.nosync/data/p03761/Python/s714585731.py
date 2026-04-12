N = int(input())
S = [input() for _ in range(N)]
result = []
for alp in 'abcdefghijklmnopqrstuvwxyz':
  tmp = []
  for i in range(N):
    tmp.append(S[i].count(alp))
  for j in range(min(tmp)):
    result.append(alp)
print(''.join(result))