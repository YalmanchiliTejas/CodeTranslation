h,w=[int(x) for x in input().split()]
a=[]
for _ in [0]*h:
    ai=list(input())
    if "#" in ai:
        a.append(ai)
tenchi=[]
for wi in zip(*a):
    if "#" in wi:
        tenchi.append(wi)
for ansi in zip(*tenchi):
    print("".join(ansi))