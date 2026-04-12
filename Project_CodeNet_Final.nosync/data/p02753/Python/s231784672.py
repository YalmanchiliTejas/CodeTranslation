S = input()
S = list(S)

ans = 'Yes'

if (S[0] == S[1]) and (S[1] == S[2]):
  ans = 'No'

print(ans)