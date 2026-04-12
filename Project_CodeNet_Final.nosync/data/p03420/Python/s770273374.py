N, K = map(int, input().split())

rlt = 0
for b in range(K+1, N+1):
  if K > 0:
    rlt += (N//b)*(b-K) + max(0, N%b - K +1)  
  else:
    rlt += (N//b)*(b-K) + max(0, N%b)  
print(rlt)