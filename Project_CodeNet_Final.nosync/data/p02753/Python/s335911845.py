a = input().strip()
A = a.count("A")
B = len(a)-A
if A and B:
  print("Yes")
else:
  print("No")