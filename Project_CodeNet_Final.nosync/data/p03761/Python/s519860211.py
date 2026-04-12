n = int(input())
s = [input() for i in range(n)]
alpha = [chr(i) for i in range(97,123)]
moji = []
ans = ''

for i in alpha:
  c = 10**10
  for j in s:
    c = min(c,j.count(i))
  moji.append(c)


for k in range(len(alpha)):
  ans += alpha[k]*moji[k]
  
print(ans)