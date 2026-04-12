h, w = map(int, input().split())
A = [input() for _ in range(h)]

sp = 0
for line in A:
  if line.find("#") != sp:  
    print("Impossible")
    exit()
  sp = line.rfind("#")
print("Possible")