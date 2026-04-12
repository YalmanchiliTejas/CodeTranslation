import sys
N, X, M = map(int, input().split())
if N == 1:
  print(X)
  sys.exit()

ans = 0
ans += X - (X%M)
X %= M

def fun(x):
  return (x * x) % M

appear_list = [X]
appear_set = {X}

x = X
i_0 = 1
sum_0 = x

while fun(x) not in appear_set:
  x = fun(x)
  appear_list.append(x)
  appear_set.add(x)
  sum_0 += x
  i_0 += 1
  #print(appear_list, x, fun(x))
  #print(i_0, N, appear_set)
  if i_0 == N:
    print(ans + sum_0)
    sys.exit()

ans += sum_0
N -= i_0

x = fun(x)
appear_set_2 = {x}
sum_1 = x
sum_list = [0,x]
i_1 = 1
while fun(x) not in appear_set_2:
  x = fun(x)
  appear_set_2.add(x)
  sum_1 += x
  sum_list.append(sum_1)
  i_1 += 1
  
sum_0 -= sum_1
i_0 -= i_1

#print(N % i_1)
ans += sum_1 * (N // i_1) + sum_list[(N % i_1)]

print(ans)



  
  
  
