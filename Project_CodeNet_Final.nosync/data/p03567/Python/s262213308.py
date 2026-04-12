S=input()
ans=1
for i in range(len(S)-1):
  if(S[i]=='A' and S[i+1]=='C'):
    print("Yes")
    ans=0
    break
if(ans):
  print("No")