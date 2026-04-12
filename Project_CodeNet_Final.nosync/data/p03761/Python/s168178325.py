n = int(input())
a = []
d = []
#

a = [input() for _ in range(n)]
d = [{} for _ in range(n)]


for i in range(n):
  for j in range(len(a[i])):
    if(not (a[i][j] in d[i])):
      d[i][a[i][j]] = 0
    d[i][a[i][j]] += 1

b = [chr(i) for i in range(97, 97+26)]
ans = ""
for j in range(len(b)):
  min = 100
  for i in range(n):
    if(not (b[j] in d[i])):
      d[i][b[j]] = 0
    if(d[i][b[j]] < min):
      min = d[i][b[j]]

  if(min != 100):
    string = b[j]*min
    ans += string

print(ans)