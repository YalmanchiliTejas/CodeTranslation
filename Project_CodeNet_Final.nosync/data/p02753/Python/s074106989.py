s=input()
a=s[0]
for i in range(2):
  if s[i+1]!=s[i]:
    print('Yes')
    exit()
print('No')