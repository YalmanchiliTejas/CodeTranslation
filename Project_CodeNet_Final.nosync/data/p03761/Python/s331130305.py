n = int(input())
a = [input() for i in range(n)]
alpha = "abcdefghijklmnopqrstuvwxyz"
len_alpha =len(alpha)
cnt_alpha = [[0]*len_alpha for i in range(n)]

for i in range(len_alpha):
  for j in range(n):
    cnt_alpha[j][i] = a[j].count(alpha[i])

#cnt_alphaの転置行列を取る(zip(*cnt_alpha))
cnt_alpha = list(zip(*cnt_alpha))

for i in range(len_alpha):
  print(alpha[i]*min(cnt_alpha[i]),end="")
print()