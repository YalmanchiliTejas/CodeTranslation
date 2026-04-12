S = input()
S = sorted(S)
a = 'Yes'
if S[0] == S[-1]:
  a = 'No'
print(a)