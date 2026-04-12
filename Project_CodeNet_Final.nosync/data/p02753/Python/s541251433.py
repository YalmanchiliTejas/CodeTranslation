char_a = input()
first = char_a[0]
count = 0
for i in [1,2]:
  if char_a[i] != first:
    count += 1
    print("Yes")
    break
if count == 0: 
  print("No")