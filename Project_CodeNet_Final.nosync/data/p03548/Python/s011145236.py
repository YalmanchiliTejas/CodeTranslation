X, Y, Z =  map(int,input().split())
X -= Z
count = 0
while True:
  if X-(Y+Z) < 0:
    break
  else:
    X -= Y+Z
    count += 1
print(count)