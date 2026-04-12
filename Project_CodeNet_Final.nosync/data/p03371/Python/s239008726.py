A, B, C, X, Y = map(int, raw_input().split())
ans = 0
if A + B < C * 2:
  ans = A*X+B*Y
else:
  num_ab_a = X*2
  num_b_a = 0 if Y-X < 0 else Y-X
  ans_a = C*num_ab_a+B*num_b_a
  num_ab_b = Y*2
  num_a_b = 0 if X-Y < 0 else X-Y
  ans_b = C*num_ab_b+A*num_a_b
  ans = ans_a if ans_a < ans_b else ans_b
print ans
