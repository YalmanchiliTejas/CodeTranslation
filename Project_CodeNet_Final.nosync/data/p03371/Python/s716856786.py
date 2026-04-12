import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
A,B,C,X,Y = map(int,readline().split())
AB = 2*max(X,Y)
price = float('inf')
for i in range(0,AB+1,2):
  total = A * max(0,X-i//2)+ B * max(0,Y-i//2) + C * i 
  price = min(price,total)
print(price)