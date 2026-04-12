list = input().split()
h = int(list[0])
w = int(list[1])

k = 0
for i in range (0,h):
   k += input().count("#")

if k == h + w - 1:
   print("Possible")
else:
   print("Impossible")
