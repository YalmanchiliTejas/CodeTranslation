a, b, c, x, y = map(int, input().split())
cos = 0
if x < y:
    flag = True
    f = y-x
else:
    flag = False
    f = x-y
if 2*c < a+b:
    cos += min(x, y)*2*c
else:
    cos += min(x, y)*(a+b)
if (2*c < a and flag == False) or (2*c < b and flag):
    cos += f*2*c
else:
    if flag:
        cos += f*b
    else:
        cos += f*a
print(cos)