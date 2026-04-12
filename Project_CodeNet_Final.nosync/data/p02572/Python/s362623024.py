N = int(input())
P = 10 ** 9 + 7
X = 0
Y = 0
for a in map(int, input().split()):
  X += a ** 2
  Y += a
  X %= P
  Y %= P
print(((Y ** 2 % P - X) * pow(2, P - 2, P)) % P)
 