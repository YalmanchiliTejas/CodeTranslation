N=int(input())
H=list(map(int,input().split()))
maxMount=0
count=0
for i in range(len(H)):
  if maxMount<=H[i]:
    count+=1
    maxMount=H[i]
print(count)