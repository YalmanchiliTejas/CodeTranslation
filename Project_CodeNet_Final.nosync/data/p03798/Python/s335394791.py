N = int(input())
s = list(input())

o = "o"
for a in [0, 1]:
  for b in [0, 1]:
    L = ["" for _ in range(N)]
    L[0] = a
    L[1] = b
    for i in range(1, N - 1):
      if s[i] == o:
        if L[i] == 0:
          L[i + 1] = L[i - 1]
        else:
          L[i + 1] = 1 - L[i - 1]
      else:
        if L[i] == 0:
          L[i + 1] = 1 - L[i - 1]
        else:
          L[i + 1] = L[i - 1]
    if s[-1] == o:
      if L[-1] == 0:
        if L[-2] != L[0]:
          continue
      else:
        if L[-2] == L[0]:
          continue
    else:
      if L[-1] == 0:
        if L[-2] == L[0]:
          continue
      else:
        if L[-2] != L[0]:
          continue
    if s[0] == o:
      if L[0] == 0:
        if L[1] != L[-1]:
          continue
      else:
        if L[1] == L[-1]:
          continue
    else:
      if L[0] == 0:
        if L[1] == L[-1]:
          continue
      else:
        if L[1] != L[-1]:
          continue
    t = ""
    for i in range(N):
      if L[i] == 0:
        t += "S"
      else:
        t += "W"
    print(t)
    exit()

print(-1)