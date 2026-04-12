H, W = map(int, input().split())
A = [list(input()) for i in range(H)]
 
A = [x for x in A if "#" in x]
A = list(zip(*A)) 
A = [x for x in A if "#" in x]
A = list(zip(*A)) 
for x in A:
  print("".join(x))