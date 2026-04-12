Tmp = []
Tmp = input().rstrip().split(' ')
 
nN = int(Tmp[0])
nX = int(Tmp[1])


nA = 1
nP = 1
 
nAnsA = []
nAnsP = []

nAnsA.append(1)
nAnsP.append(1)
 
for i in range(nN):
  nTmpA = nA * 2 +3
  nTmpP = nP * 2 +1
  nAnsA.append(nTmpA)
  nAnsP.append(nTmpP)
  nA = nTmpA
  nP = nTmpP

nAnsA.sort(reverse=True)  
nAnsP.sort(reverse=True)  
nN += 1

nMaxA = nAnsA[0]
nMaxP = nAnsP[0]
 
nTmpA = nMaxA
nTmpP = nMaxP
 
nAns = 0

# print(nAnsA)
# print(nAnsP)


for i in range(nN):
#  print(nX)
  if i == nN - 1:
    nAns += 1
    break
  else:
    nTmpA = nAnsA[i+1] + 2
    nTmpP = nAnsP[i+1] + 1
#  print(nTmpA)
#  print(nTmpP)

  
  if nTmpA > nX:
    nX -= 1
    if (nX == 0):
      break
  elif nTmpA == nX:
    nAns += nTmpP
    break
  else:
    nAns += nTmpP
    nX -= nTmpA
#  print(nAns)
    
print(nAns)
 