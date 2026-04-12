inp1 = input().split()
a = int(inp1[0])
b = int(inp1[1])

if b ==0:
  print("No")
else:
  c = a%b
  if c == 0:
    print("Yes")
  else:
    print("No")