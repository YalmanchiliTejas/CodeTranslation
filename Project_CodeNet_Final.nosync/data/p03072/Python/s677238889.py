mountain = input()
viewpoint = input().split()
maxheight = 0
canview = 0

for i in range(0, int(mountain)):
    if maxheight <= int(viewpoint[i]):
        maxheight = int(viewpoint[i])
        canview += 1

print(canview)
