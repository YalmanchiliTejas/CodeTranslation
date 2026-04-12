import sys
lines = sys.stdin.readlines()
sizes = lines[0].split(" ")
H = int(sizes[0])
W = int(sizes[1])
field = []
for line in lines[1:]:
    field.append(line.rstrip())

#print (field)
count=0
for f in field:
    for i in range(W):
        s = f[i:i+1]
        if s=="#":
            count+=1


posQ = [[0,0]]

now = [0,0]
before = [-1,0]

while(now[0]+1<H or now[1]+1<W):
    if (before==now):
        break
    #print (now)
    if now[1]+1<W:
        if field[now[0]][now[1]+1:now[1]+2] == "#":
            posQ.append([now[0],now[1]+1])
    if now[0]+1<H:
        if field[now[0]+1][now[1]:now[1]+1] == "#":
            posQ.append([now[0]+1,now[1]])
    before = now
    now = posQ[len(posQ)-1]

"""
now = [0,0]

if field[now[0]][now[1]+1:now[1]+2] == "#":
    posQ.append([now[0],now[1]+1])
if field[now[0]+1][now[1]:now[1]+1] == "#":
    posQ.append([now[0]+1,now[1]])

now = posQ[len(posQ)-1]

if field[now[0]][now[1]+1:now[1]+2] == "#":
    posQ.append([now[0],now[1]+1])
if field[now[0]+1][now[1]:now[1]+1] == "#":
    posQ.append([now[0]+1,now[1]])


"""

#print (posQ)
#print (len(posQ))
if (len(posQ)!=H+W-1):
    print("Impossible")
else:
    if (count>len(posQ)):
        print("Impossible")
    else:
        print("Possible")
