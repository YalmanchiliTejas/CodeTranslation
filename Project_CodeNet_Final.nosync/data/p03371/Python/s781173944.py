a, b, c, x, y = map(int, input().split())
a_l = []


def abs0(inp):
    if inp < 0:
        return 0
    else:
        return inp


for i in range(x+1):
    a_l.append(a*i + c*2*(x-i) + b*abs0(y-(x-i)))
b_l = []
for i in range(y+1):
    b_l.append(b*i + c*2*(y-i) + a*abs0(x-(y-i)))
print(min(a_l + b_l))
