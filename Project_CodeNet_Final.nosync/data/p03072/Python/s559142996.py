N = int(input())
H = list(map(int,input().split(' ')))

count = 1
for i in range(1,N,1):
  h = max(H[:i])
  if H[i] >= h:
    count += 1
  
print(count)