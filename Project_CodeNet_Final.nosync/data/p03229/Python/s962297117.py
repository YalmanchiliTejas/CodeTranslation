N = int(input())
L = []
S = 0
K = 0
for i in range(N):
  L.append(int(input()))
L.sort()
if N == 2:
  print(abs(L[0]-L[1]))
elif N == 3:
  print(max(abs(L[2]+L[1]-2*L[0]),abs(2*L[2]-L[1]-L[0])))
elif N == 4:
  print(abs(2*L[3]+L[2]-L[1]-2*L[0]))
elif N%2 == 0:
  for i in range((N-2)//2):
    S += 2*(L[N-i-1]-L[i])
  S += L[N//2]-L[(N-2)//2]
  print(S)
else:
  for i in range((N-3)//2):
    S += 2*L[N-i-1]
  for j in range(N//2):
    S -= 2*L[j]
  S += L[N//2]+L[N//2+1]
  for k in range(N//2):
    K += L[N-k-1]*2
  for m in range((N-3)//2):
    K -= 2*L[m]
  K -= (L[N//2]+L[N//2-1])
  print(max(S,K))