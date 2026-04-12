h,w = map(int,input().split())
c = [0]*(h+2)

r = 0

for i in range(1,h+1):
    c[i] = [0] + list(input()) + [0]
    r += c[i].count("#")
c[0]  = [0]*(w+2)
c[-1] = [0]*(w+2)

x,y = 1,1

q = 0
ans = 1
while 1:
    if x == h and y == w:
        break
    
    s = 0
    t = 0
    if c[x+1][y] == "#":
        s = 1
    if c[x][y+1] == "#":
        t = 1
            
    if s == 1 and t == 1:
        ans = 0
        break
    elif s == 0 and t == 0:
        ans = 0
        break
    elif s == 1:
        x += 1
        q += 1
    else:
        y += 1
        q += 1
if q + 1 != r:
    ans = 0

print(["Impossible","Possible"][ans])