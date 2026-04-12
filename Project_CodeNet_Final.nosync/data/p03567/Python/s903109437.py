S = input()
N = len(S)
for i in range (N-1):
  if(S[i]=='A' and S[i+1]=='C'):
    print("Yes")
    exit()
print("No")