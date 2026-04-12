N = int(input())
H = [int(i) for i in (input()).split(" ")]

maxH = 0
seeN = 0
for i in range(N):
  if(maxH<=H[i]):
    maxH = H[i]
    seeN += 1
print(seeN)
