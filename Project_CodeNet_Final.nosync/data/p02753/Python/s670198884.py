S = input()
n = len(S)
if n == 3:
  a = S.split()
  x = S[0]
  y = S[1]
  z = S[2]
  if x != y or y != z:
    print("Yes")
  else:
    print("No")