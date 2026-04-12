n = int(input())
arr = [int(x) for x in input().split()]
ans = 1

cm = arr[0]

for i in range(1,n):
  cm = max(cm,arr[i])
  if arr[i] == cm:ans+=1
    
print(ans)