n = int(input())
s = [sorted((input())) for _ in range(n)]
d = [{} for _ in range(n)]
for i in range(n):
  for j in range(len(s[i])):
    if s[i][j] in d[i]:
      d[i][s[i][j]] += 1
    else:
      d[i][s[i][j]] = 1
ans = ''
for i in d[0].keys():
  cnt = d[0][i]
  for j in range(1,n):
    if i in d[j]:
      cnt = min(cnt,d[j][i])
    else:
      break
    if j == n-1:
      ans += '{}'.format(i*cnt)
if n >= 2:
  print(''.join(sorted(ans)))
else:
  print(''.join(sorted(s[0])))