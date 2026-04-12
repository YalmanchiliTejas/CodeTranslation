A,B,C,X,Y = map(int,input().split(' '))
MIN = float('inf')

for i in range(0,2*max(X,Y)):
  sum = C*2*i + max(0,X-i)*A + max(0,Y-i)*B
  MIN = min(MIN,sum)
print(MIN)