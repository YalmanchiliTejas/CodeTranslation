N = int(input())
H = list(map(int,input().split()))
T = 0
a = 0

for n in range(N):
  if n!=0:
    T = max(H[:n])
  if T<=H[n]:
    a+=1

print(a)