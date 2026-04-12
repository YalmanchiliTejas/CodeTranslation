s = input()
ans = 'No'
n = len(s)
for i in range(n-1):
  if s[i:i+2] =='AC': ans = 'Yes'
print(ans)