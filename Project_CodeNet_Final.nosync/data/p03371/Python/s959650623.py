a,b,c,x,y = [int(i) for i in input().split()]
P = [0, x, y]
while P[1]>0 or P[2]>0:
  if P[1]>0 and P[2]>0 and a+b>c*2:
    P[0] += c*2
    P[1] -= 1
    P[2] -= 1
  elif P[1]>0 and P[2]>0 and c*2>a+b:
    P[0] += a+b
    P[1] -= 1
    P[2] -= 1
  elif P[1]>0 and a>c*2:
    P[0] += c*2
    P[1] -= 1
    P[2] -= 1
  elif P[2]>0 and b>c*2:
    P[0] += c*2
    P[1] -= 1
    P[2] -= 1
  elif P[1]>0:
    P[0] += a
    P[1] -= 1
  elif P[2]>0:
    P[0] += b
    P[2] -= 1
print(P[0])