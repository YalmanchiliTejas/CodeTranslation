import sys

inputted_string = ''
for line in sys.stdin:
  inputted_string = line
 
if int(inputted_string.replace(" ", "")) % 4 is 0:
  print('YES')
else:
  print('NO')