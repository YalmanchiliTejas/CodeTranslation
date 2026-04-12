N = int(input())
A = list(map(int, input().split()))
base = 10 ** 9 + 7
X = 0
Y = 0
for i in A:
  X += i * i
  Y += i
  X %= base
  Y %= base
Y = (Y * Y) % base
ans_ = ( Y - X ) % base

m = pow(2, base-2, base)
#print(m)
print( (ans_ * m) % base )