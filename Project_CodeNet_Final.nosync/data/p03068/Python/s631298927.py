n = int(input())
rawa = input()
n1 = int(input())
a = ""
b = rawa[n1-1]
for i in range(n):
  if rawa[i] == b:
    a += b
  else:
    a += "*"
print(a)