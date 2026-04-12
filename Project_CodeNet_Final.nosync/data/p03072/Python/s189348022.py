n=int(input())
H=list(map(int,input().split()))
count=0
h=H[0]
for i in range(n):
  if h<=H[i]:
    h=H[i]
    count+=1
print(count)