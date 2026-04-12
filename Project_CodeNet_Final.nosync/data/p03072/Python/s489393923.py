N=int(input())
H=list(map(int,input().split()))
data=[]
count=0

for i in range(N):
  data.append(H[i])
  ma=max(data)
  if H[i]>=ma:
    count=count+1
    
print(count)
    