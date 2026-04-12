S=input()
import sys
for i in range(2):
  if S[i]==S[i+1]:
    continue
  else:
    print('Yes')
    sys.exit()
print('No')
    