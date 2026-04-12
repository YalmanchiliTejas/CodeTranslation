h, w = map(int, input().split())
arr = [list(input()) for i in range(h)]
 
arr = [x for x in arr if "#" in x]
arr = list(zip(*arr)) # transpose
arr = [x for x in arr if "#" in x]
arr = list(zip(*arr)) # transpose
for x in arr:
  print("".join(x))