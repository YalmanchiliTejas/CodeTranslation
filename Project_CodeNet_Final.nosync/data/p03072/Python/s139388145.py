N=int(input())
H=list(map(int, input().split()))

counter=0
for i in range(N-1):
  if max(H[:(i+1)])==H[i]:
    counter+=1
    
if max(H)==H[N-1]:
  counter+=1
  
print(int(counter))