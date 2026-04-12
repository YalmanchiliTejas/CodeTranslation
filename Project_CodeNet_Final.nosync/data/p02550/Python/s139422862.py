N,X,M = map(int, input().split())

A = [X]
x = (X**2)%M

while x not in A:
  A.append(x)
  x = (x**2)%M

if len(A) >= N:
  answer = sum(A[:N])
else:
  index = 0
  while A[index] != x:
    index += 1
  len_loop = len(A) - index
  num_loop = (N-index)//len_loop
  num_last = N - index - len_loop*num_loop
  answer = sum(A[:index]) + num_loop*sum(A[index:]) + sum(A[index:index+num_last])

print(answer)