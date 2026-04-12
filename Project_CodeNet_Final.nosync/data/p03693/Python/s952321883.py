msg=input().split()
number=int(msg[0])*100+int(msg[1])*10+int(msg[2])
if number%4==0:
  print("YES")
else:
  print("NO")