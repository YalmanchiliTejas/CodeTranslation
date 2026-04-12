h,w = map(int, input().split())
a=[]
A=[[i for i in input()] for _ in range(h)]
B=[x for x in A if "#" in x]
C = zip(*[y for y in zip(*B) if "#" in y])
for d in C:print("".join(d))