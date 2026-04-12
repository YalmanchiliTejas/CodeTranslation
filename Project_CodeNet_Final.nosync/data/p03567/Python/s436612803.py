S = input()
for s, ns in zip(S, S[1:]):
  if s + ns == "AC":
    print("Yes")
    exit()
print("No")