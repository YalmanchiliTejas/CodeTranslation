N = int(input())

H = [int(i) for i in input().split()]

count = 1

for i in range(1,N):
  if max(H[:i+1]) == H[i]:
    count +=1
    
    
print(count)

