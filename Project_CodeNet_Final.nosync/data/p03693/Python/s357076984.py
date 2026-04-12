s = input().split()
p = [int(w) for w in s]

r = p[0]
g = p[1]
b = p[2]

t = r * 100 + g * 10 + b
if(t%4 == 0):
    print('YES')
else:
    print('NO')