argN = int(input())
argS = input()
argK = int(input())

aryS = list(argS)

for i in range(argN):
  if aryS[i] == aryS[argK-1]:
    pass
  else:
    aryS[i] = "*"
print("".join(aryS))