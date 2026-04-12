h,w = (int(x) for x in input().split())
ab = []
count = 0
for _ in range(h):
    a = input()
    a = a+'.'
    a=list(a)
    for i in a:
        if i == '#':
            count += 1
    ab.append(a)
ab.append(list('.'*w))

if count != h+w-1:
    print('Impossible')
    exit()
            
step = [[0, 0]]
 
while len(step) > 0:
    y, x = step.pop(0)
    if y == h-1 and x == w-1:
        print('Possible')
        exit()
    if ab[y+1][x] == '#' :
        step.append([y+1, x])
    elif ab[y][x+1] == '#' :
        step.append([y, x+1])

print('Impossible') 