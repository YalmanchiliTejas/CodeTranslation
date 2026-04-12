n = int(input())
S = [input() for i in range(n)]
al = "abcdefghijklmnopqrstuvwxyz"
count = [[0 for i in range(len(al))] for j in range(n)]

for i in range(n):
  for j in range(len(al)):
    count[i][j] = S[i].count(al[j])

ans = ''
for j in range(len(al)):
  num = 999
  for i in range(n):
    if count[i][j] < num:
      num = count[i][j]
  if num != 0:
    for k in range(num):
      ans+=al[j]
      
print(ans)