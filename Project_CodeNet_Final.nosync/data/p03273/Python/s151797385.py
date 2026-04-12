H,W=list(map(int,input().split()))
a=[list(input()) for h in range(H)] 

a=list(zip(*[i for i in a if "#" in i]))
a=list(zip(*[i for i in a if "#" in i]))

for n in range(len(a)):
  print("".join(a[n]))
