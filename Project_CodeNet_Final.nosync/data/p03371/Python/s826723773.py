#coding: utf-8

s = input().split(" ")
a = int(s[0])
b = int(s[1])
c = int(s[2])
x = int(s[3])
y = int(s[4])

out = 0
if x > y:
    mx = (x - y , "a")
    my = y
else:
    mx = (y - x , "b")
    my = x

cc = min([a+b, c*2])
for i in range(my):
    out += cc
if mx[1] == "a":
    if cc > a:
        out += a * mx[0]
    else:
        out += cc * mx[0]
else:
    if cc > b:
        out += b * mx[0]
    else:
        out += cc * mx[0]

print(out)