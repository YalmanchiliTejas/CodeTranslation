MM = input().split()
X = int(MM[0])
Y = int(MM[1])
Z = int(MM[2])
x = 0
while True:
  if x*(Y+Z)+Z >X:
    break
  else:
    x +=1
print(x-1)