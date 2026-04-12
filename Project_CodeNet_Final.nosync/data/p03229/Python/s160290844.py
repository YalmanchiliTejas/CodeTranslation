N, *A = map(int, open(0).read().split())
A.sort()

if N % 2:
  array1 = [-2] * (N // 2) + [1] * 2 + [2] * (N // 2 - 1)
  array2 = [-2] * (N // 2 - 1) + [-1] * 2 + [2] * (N // 2)
  
  ret1 = 0
  ret2 = 0
  for i in range(N):
    ret1 += A[i]*array1[i] 
    ret2 += A[i]*array2[i]
  ret = max(ret1, ret2)

else:
  array1 = [-2] * (N // 2 - 1) + [-1] + [1] + [2] * (N // 2 - 1)
  
  ret = 0
  for i in range(N):
    ret += A[i]*array1[i] 
  
print(ret)