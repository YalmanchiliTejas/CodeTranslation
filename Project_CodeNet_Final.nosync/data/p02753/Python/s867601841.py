mogi = input()

first = mogi[0]
use_bus = False

for i in range(len(mogi)):
  if first != mogi[i]:
    use_bus = True
    break

if use_bus:
  print("Yes")
else:
  print("No")
