a = int(input())
b = list(input())
c = int(input())
for i in range(a):
  if b[i] != b[c-1]:
    b[i] = "*"
print("".join(b))
    
