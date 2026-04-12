a = int(input())
b = input()
c = int(input())
for i in range(a):
  if b[i] == b[c-1]:
    print(b[i], end="")
  else:
    print("*", end="")