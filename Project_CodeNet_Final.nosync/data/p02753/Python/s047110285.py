n = list(input())
s = 'S'
ans = 'No'
for i in range(3):
  s = n[i]
  if i <= 1:
    if s != n[i+1]:
      ans = 'Yes'
print(ans)