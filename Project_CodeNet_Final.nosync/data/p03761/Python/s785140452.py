n = int(input())
a = [input() for i in range(n)]
alpha = "abcdefghijklmnopqrstuvwxyz"
cnt_alpha = [[0]*len(alpha) for i in range(n)]

for i in range(len(alpha)):
  for j in range(n):
    cnt_alpha[j][i] = a[j].count(alpha[i])

cnt_alpha = [[row[i] for row in cnt_alpha] for i in range(len(alpha))]
for i in range(len(alpha)):
  print(alpha[i]*min(cnt_alpha[i]),end="")
print()