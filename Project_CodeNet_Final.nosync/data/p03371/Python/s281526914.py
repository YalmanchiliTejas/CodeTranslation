A, B, C, X, Y = map(int, input().split())

min_value = X if (X < Y) else Y

total = 0
if (A + B > C * 2):
  total = C * 2 * min_value
else:
  total = (A + B) * min_value

current_X = X - min_value
current_Y = Y - min_value
if(current_X != 0):
  if(A > C * 2):
    total += current_X * C * 2
  else:
    total += current_X * A
else:
  if(B > C * 2):
    total += current_Y * C * 2
  else:
    total += current_Y * B
print(total)