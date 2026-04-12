S=input()
for i in range(len(S)-1):
  if S[i] == 'A' and S[i+1] == 'C':
    print('Yes')
    exit()
    
print('No')