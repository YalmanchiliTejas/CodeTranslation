N = int(input())
A = []
for i in range(N):
  temp = int(input())
  A.append(temp)
A.sort()

if N%2 == 0:
  c = N//2
  small = A[:c]
  large = A[c:]
  ans = 2*sum(large)-min(large)-(2*sum(small)-max(small))
else:
  c = N//2
  small = A[:c+1]
  small.sort()
  large = A[c+1:] #largeの数のほうが少ない
  ans = 2*sum(large)-(2*sum(small)-small[-1]-small[-2])
  #print(large,small)
  small = A[:c]
  large = A[c:]
  large.sort()
  anst = 2*sum(large)-large[0]-large[1]-2*sum(small)
  ans = max(ans,anst)
print(ans)