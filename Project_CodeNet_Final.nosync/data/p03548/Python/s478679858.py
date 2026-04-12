x,y,z = map(int,input().split())
people = 0
x = x-2*z
while x-y >=0:
  x = x-y
  people += 1
  x -= z 
print(people)
  