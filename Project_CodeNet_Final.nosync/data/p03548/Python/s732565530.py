x,y,z = map(int,input().split())
i = 1
while True:
  if x < y * i + z * (i+1):
    print(i-1)
    break
  i += 1