n=int(input())
towers=[]
for i in range(n):
    towers.append([])
res=[]
while True:
    Str=input()
    if Str == "quit":
        break
    Slst= Str.split()
    if Slst[0] == "push":
        towers[int(Slst[1])-1].append(Slst[2])
    elif Slst[0] == "move":
        towers[int(Slst[2])-1].append(towers[int(Slst[1])-1].pop())
    else:
        res.append(towers[int(Slst[1])-1].pop())
for i in res:
    print(i)