S = str(input())

bool1 = S[0] == S[1]
bool2 = S[1] == S[2]
bool3 = S[2] == S[0]

if bool1*bool2*bool3:
  print('No')
else:
  print('Yes')