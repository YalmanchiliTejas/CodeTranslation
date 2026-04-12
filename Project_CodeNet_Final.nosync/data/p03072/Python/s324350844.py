N = int(input())
H = list(map(int,input().split()))
a = 1

for n in range(1,N):
  if max(H[:1+n])==H[n]:
    a+=1

print(a)