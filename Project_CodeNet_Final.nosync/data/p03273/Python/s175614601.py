hw = [int(i) for i in input().split()]
a = [list(input()) for _ in range(hw[0])]
for i in range(2):
  c = 0
  for ai in a:
    if all([aij == "." for aij in ai]):
      c += 1
  for j in range(c):
    a.remove(["."] * len(a[i]))
  a = [list(ai) for ai in zip(*a)]
for ai in a:
  print("".join(ai))