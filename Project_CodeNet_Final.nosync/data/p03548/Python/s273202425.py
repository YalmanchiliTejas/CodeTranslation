x, y, z = map(int, input().split())
p = 1

for i in range(x//y):
    if x-(p+2)*z-p*y<y:
        break
    else:
        p+=1

print(p)