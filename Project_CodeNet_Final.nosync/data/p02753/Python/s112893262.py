S = list(input())

T = list(set(S))

if len(T) == 1:
  print("No")
else:
  print("Yes")