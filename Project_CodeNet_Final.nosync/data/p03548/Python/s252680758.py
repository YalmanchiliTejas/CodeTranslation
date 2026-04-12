X, Y, Z = list(map(int, input().split()))
for i in range(0, 10**5+1):
  if X - (i*Y + (i+1)*Z) == 0:
    print(i)
    exit()
  if X - (i*Y + (i+1)*Z) < 0:
    print(i-1)
    exit()