S=input()
count=0
for i in range(2):
  if S[i]==S[i+1]:
    count+=1
if count==2:
  print("No")
else:
  print("Yes")