n = int(input())
A = [int(input()) for _ in range(n)]
A = sorted(A,reverse=True)

ans = 0
if n%2 == 1:
  i = -1
  for i in range((n-2)//2):
    ans += A[i]*2
    ans -= A[-i-1]*2    
  ans += A[i+1]
  ans += A[i+2]
  ans -= A[i+3] *2
  
  tmp = 0
  for i in range((n-2)//2):
    tmp += A[i]*2
    tmp -= A[-i-1]*2    
  tmp += A[i+1] *2
  tmp -= A[i+2]
  tmp -= A[i+3]
  ans = max(ans,tmp)
  
else:
  i = -1
  for i in range((n-2)//2):
    ans += 2*A[i]
    ans -= 2*A[-i-1]      
  ans += A[i+1]
  ans -= A[i+2]
  
print(ans)  