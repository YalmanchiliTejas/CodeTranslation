#ISU
x,y,z = map(int,input().split())
n = 1

x = x - y - 2*z
for _ in range(x//y):
    if x - y - z >= 0:
        x = x-y-z
        n += 1
    else:
        break

print(n)