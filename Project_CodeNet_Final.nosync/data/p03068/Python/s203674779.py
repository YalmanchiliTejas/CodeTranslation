n = int(input())
s = input()
k = int(input())
ans = []
j = s[k-1]
for i in s:
  if i !=j:
    ans.append('*')
  else:
    ans.append(i)
print(''.join(ans))