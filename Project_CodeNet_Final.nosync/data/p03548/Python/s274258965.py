x,y,z = map(int, input().split())

for i in range(1,x+1):
   tmp = x - z*(i+1) - y*i
   if tmp < 0 :
      print(i-1)
      break
