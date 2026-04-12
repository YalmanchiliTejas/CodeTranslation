input_line = list(map(int,input().split()))
result = input_line[0] - input_line[1]
if result == 0:
  print('Yes')
else:
  print('No')