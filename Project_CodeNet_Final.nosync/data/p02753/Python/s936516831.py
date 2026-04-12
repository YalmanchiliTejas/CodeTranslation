S = input()

S_list = [i for i in S]
S_set = set(S_list)

if len(S_set) == 2:
  print('Yes')
else:
  print('No')