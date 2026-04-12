a,b,c = input().split()

last_2digits = b + c

if int(last_2digits) % 4 == 0:
 	print("YES")
else:
  	print("NO")