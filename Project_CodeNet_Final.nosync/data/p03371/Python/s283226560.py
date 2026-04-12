A,B,C,X,Y = map(int,input().split())
C *= 2
ax = 0
bx = 0
num = 0
while ax < X or bx < Y:
  if ax < X and bx < Y:
    if A+B < C:
      num += A+B
    else:
      num += C
    ax += 1
    bx += 1
  elif ax < X:
    if A < C:
      num += A
    else:
      num += C
    ax += 1
  else:
    if B < C:
      num += B
    else:
      num += C
    bx += 1
print(num)

    