S = input().strip()
for k in range(len(S)-1):
  if S[k]+S[k+1] == 'AC':
    print('Yes')
    break
else:
  print('No')