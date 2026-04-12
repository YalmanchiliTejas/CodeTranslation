while True:
  N,A,B,C,X = map(int, raw_input().split())
  if N==A==B==C==X==0: break
  y = map(int, raw_input().split())
  it = 0
  counter = 0
  x = X
  while True:
    if x == y[it]: it += 1
    if it == N or counter > 10000: break
    x = (A*x+B)%C
    counter += 1
  if counter > 10000:
    print "-1"
  else:
    print counter