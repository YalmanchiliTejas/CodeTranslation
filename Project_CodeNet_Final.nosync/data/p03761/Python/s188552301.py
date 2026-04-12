n = int(input())
alphabet = list('abcdefghijklmnopqrstuvwxyz')
ans = [100]*26

for i in range(n):
  S = list(input())
  tmp = [0]*26
  for j in range(len(S)):
    for k in range(26):
      if(S[j] == alphabet[k]): tmp[k] += 1
  for j in range(26):
    if(ans[j] > tmp[j]): ans[j] = tmp[j]
   
ans_str = ''
for i in range(26):
  for j in range(ans[i]):
    ans_str += alphabet[i]
print(ans_str)