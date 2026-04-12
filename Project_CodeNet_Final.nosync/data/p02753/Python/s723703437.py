stations=input()
if stations[1]!=stations[0]:
  print('Yes')
elif stations[1]!=stations[2]:
  print('Yes')
elif stations[0]!=stations[2]:
  print('Yes')
else:
  print('No')