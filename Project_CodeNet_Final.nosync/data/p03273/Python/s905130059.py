h,w=map(int,input().split())
A=[[i for i in input()] for j in range(h)]
B=[a for a in A if "#" in a]
C=[b for b in zip(*B) if "#" in b]
for c in zip(*C):
  print(*c,sep="")