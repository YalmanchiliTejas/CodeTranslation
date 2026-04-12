N, X, M = map(int, input().split())

visited = [-1] * (M + 1)
x = X
i = 0
while visited[x] == -1 :
  visited[x] = i
  x = x * x % M
  i += 1

loop_l = i - visited[x]
loop_s = x

ret = 0
x = X
while x != loop_s :
  ret += x
  x = x * x % M
  N -= 1
  if N == 0 : break
    
if N > 0 :
  i = 0
  while i != loop_l :
    ret += x * ((N - i + loop_l - 1) // loop_l)
    x = x * x % M
    i += 1
  
print(ret)