S = input()

s = list(S)

ans = 'Yes'

if (s[0] == s[1]) and (s[1] == s[2]):
  ans = 'No'

print(ans)