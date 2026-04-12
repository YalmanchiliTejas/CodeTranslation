a = input()
c = 'No'
for i in range(2):
  if a[i] != a[i+1]:
    c = 'Yes'
    break
print(c)