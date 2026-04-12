inputstring = input()
count = 0
if len(inputstring) == 3:
  for i in inputstring:
    if i == 'A':
      count = count + 0
    else:
      count = count + 1
  if count == 0 or count == 3:
    print("No")
  else:
    print("Yes")
else:
  print()
