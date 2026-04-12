N = int(input())
count = 0
total = 0
H = []
s = input().split()

for i in range(N):
  H.append(int(s[i]))
  for j in range(i):
    if(H[i] >= H[j]):
      count = count + 1
  if(count == i):
    count = 0
    total = total + 1
  count = 0
    
print(total)