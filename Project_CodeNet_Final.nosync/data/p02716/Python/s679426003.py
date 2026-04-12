N = int(input())
a = list(map(int, input().split()))

C = [0 for _ in range(N)] #奇数個、余裕あり
D = [0 for _ in range(N)] #偶数個
E = [0 for _ in range(N)] #奇数個、余裕なし

E[0] = a[0]

for i in range(1,N):
  if i % 2 == 0:#奇数個
    C[i] = max(C[i-2]+a[i],D[i-1])
    E[i] = E[i-2] + a[i]
  else:
    D[i] = max(D[i-2]+a[i],E[i-1])

if N % 2 == 0:
  print(D[N-1])
else:
  print(C[N-1])
  
#print(C)
#print(D)
#print(E)
    

