N = int(input())
H = list(map(int, input().split()))
c=0
for i in range(N):
  l=H[:i+1]
  if max(l) == H[i]:
    c += 1
print(c)