maze = []
h, w = map(int,input().split())
for _ in range(h):
    maze.append(list(input()))
#print(maze)
x,y = 0,0
while True:
    maze[y][x] = "."
    if x == w-1 and  y == h-1:
        break
    if x != w-1 and maze[y][x+1]== "#":
        x += 1
        continue
    if y != h-1 and maze[y+1][x]=="#":
        y += 1
        continue
    break
from pprint import pprint
#pprint(maze)
f= True
for i in range(h):
    if maze[i].count("#") != 0:
        f = False
print("Impossible" if not f else "Possible")
