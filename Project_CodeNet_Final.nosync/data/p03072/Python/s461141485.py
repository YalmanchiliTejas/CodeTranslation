N = int(input())
H = list(map(int,input().split()))
counter = 1
for i in range(1,N):
  bool = True
  for j in range(0,i):
    if H[j] > H[i]:
      bool = False
  if bool:
    counter += 1
print(counter)