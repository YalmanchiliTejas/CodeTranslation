h,w = map(int, input().split())
a = ""
for i in range(h):
  a = a + input()
if a.count("#") == h + w -1:
  print("Possible")
else:
  print("Impossible")