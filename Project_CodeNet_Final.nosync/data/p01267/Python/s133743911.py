while True:
  N,A,B,C,X = map(int,raw_input().split())
  if N == A == B == C == X == 0:break
  sum = 0
  Z = 0
  Y = [int(x) for x in raw_input().split()]
  if X == Y[0]:
      Y.pop(0)
      if len(Y) == 0:
          Z = 1
  while Z == 0:
      if sum == 10000:
          sum = -2
          Z = 1
      sum += 1
      X = (A*X+B)%C
      if X == Y[0]:
          Y.pop(0)
          if len(Y) == 0:
              Z = 1
  print sum