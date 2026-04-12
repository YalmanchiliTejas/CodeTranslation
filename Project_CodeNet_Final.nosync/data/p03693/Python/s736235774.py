l = input().split(' ')
r = int(l[0])
g = int(l[1])
b = int(l[2])
a = 100*r + 10*g + b
mod = a % 4
if mod == 0 :
    print('YES')
else:
    print('NO')