# A Station and Bus

S = input()

bef = S[0]
for s in S[1:]:
  if s != bef:
    print("Yes")
    exit()
  else:
    bef = s
print("No")