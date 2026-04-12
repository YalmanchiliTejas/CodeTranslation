def main():
  t = input().split(" ")
  A, B, C, X ,Y = int(t[0]), int(t[1]), int(t[2]), int(t[3]), int(t[4])
  a_p = min(A, 2*C)
  b_p = min(B, 2*C)
  set_p = min(A+B, 2*C)
  set_n = min(X, Y)
  a_n = X - set_n
  b_n = Y - set_n
  r = a_p * a_n + b_p * b_n + set_p * set_n
  print(r)
main()