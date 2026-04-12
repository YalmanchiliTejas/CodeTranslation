N=int(input())
H=list(map(int,input().split()))

count=1
l=H[0]
for i in range(N-1):
  if H[i+1]-l>=0:
    count +=1
    l=H[i+1]
print(count)
