xyz = list(map(int,input().split()))
x = 0
for i in range(100000):
    x += 1
    if xyz[0] < (x*(xyz[1]+xyz[2])+xyz[2]):
        x -= 1
        break
print(x)