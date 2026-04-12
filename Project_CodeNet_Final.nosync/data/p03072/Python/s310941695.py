N=int(input())
H=list(map(int,input().split()))

max=0
count=0
for i in range(len(H)):
  if H[i] >= max:
    max = H[i]
    count += 1

print(count)