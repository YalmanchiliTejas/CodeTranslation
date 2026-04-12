n = int(input())
S = input()
i = int(input())
for s in S:
  print(s, end = '') if s == S[i-1] else print('*', end = '')
  
  