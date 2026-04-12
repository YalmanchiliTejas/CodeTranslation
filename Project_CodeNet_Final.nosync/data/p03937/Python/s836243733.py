H, W = map(int,input().split())
S = [input() for _ in range(H)]
endSh = 0
for i in S:
  startSh = i.find("#")
  if startSh != endSh:
    print("Impossible")
    exit()
  endSh = i.rfind("#")
print("Possible")