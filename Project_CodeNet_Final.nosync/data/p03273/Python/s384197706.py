
def rem(a):
    res = []
    for x in a:
        if x.count('#') > 0:
            res.append(x)
    return res

h,w=map(int,input().split())
a = [list(input()) for _ in range(h)]

while a != rem(a):
    a = rem(a)


a = list(zip(*rem(list(zip(*a)))))

for x in a:
    print("".join(x))