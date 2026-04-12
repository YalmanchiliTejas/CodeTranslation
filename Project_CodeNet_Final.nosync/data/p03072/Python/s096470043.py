N = int(input())
H = list(map(int,input().split()))
z = 1

for i in range(1,N):
  if max(H[:i+1])==H[i]:
    z+=1

print(z)