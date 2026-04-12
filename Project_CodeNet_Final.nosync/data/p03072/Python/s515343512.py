N = int(input())
H = input().split(" ")
count = 0
for i in range(N):
  if i == 0:
    nowTop = H[0]
    count += 1
  else:
    if int(H[i]) >= int(nowTop):
      nowTop = H[i]
      count += 1
      
print(count)