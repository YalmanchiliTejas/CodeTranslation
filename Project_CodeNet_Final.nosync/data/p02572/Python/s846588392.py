N = int(input())
array = list(map(int,input().split()))
ans = 0
kuso = sum(array)
for i in range(N-1):
  kuso -= array[i]
  ans += array[i]*kuso  
print( ans%(10**9+7) )