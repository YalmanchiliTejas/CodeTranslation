h,w=map(int,input().split())
sij=[[x for x in input()] for _ in range(h)]
sijd=[line for line in sij if "#" in line]
sijdd=zip(*[line for line in zip(*sijd) if "#" in line])
for line in sijdd:
    print("".join(line))