S=list(input())
count=0
for i in range(2):
  if not S[i]==S[i+1]:
    count+=1
if count >= 1:
  print('Yes')
else:
  print('No')