N = int(input())

ansA = {}
for ch in "abcdefghijklmnopqrstuvwxyz":
  ansA[ch] = 100
temp = {}
for ch in "abcdefghijklmnopqrstuvwxyz":
  temp[ch] = 0

for i in range(N):
  for ch in "abcdefghijklmnopqrstuvwxyz":
    temp[ch] = 0
  st = input()
  for ch in st:
    temp[ch] = temp[ch] + 1
  
  for ch in "abcdefghijklmnopqrstuvwxyz":
    ansA[ch] = min(ansA[ch], temp[ch])
    
for ch in "abcdefghijklmnopqrstuvwxyz":
  print( ch * ansA[ch], end="")
  
  