c = int(input())
H = input().split()

count = 1
for i in range(c-1):
  v = True
  for j in range(i+1):
    if int(H[i+1]) < int(H[j]):
      v = False
      break
  if v:
    count += 1
print(count)