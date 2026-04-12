H,W=map(int,input().split())
A=[input() for i in range(H)]
b=[x for x in A if "#" in x]
c=zip(*[y for y in zip(*b) if "#" in y])
for d in c:print("".join(d))