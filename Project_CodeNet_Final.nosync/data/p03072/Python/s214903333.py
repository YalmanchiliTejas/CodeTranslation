input()
H = list(map(int, input().split()))
N = len(H)

n = 0
for i in range(N):
  for h in H[:i]:
    if h > H[i]:
      break
  else:
    n += 1
      
print(n)