
def getint(): return int(input())
def getints(): return list(map(int, input().split()))

a,b,c,x,y=getints()

res = x*a + y*b
for c_count in range(0, max(x,y)*2 + 2, 2):
    x_need = max(0, x - c_count // 2)
    y_need = max(0, y - c_count // 2)
    tmp = x_need * a + y_need * b + c_count * c
    res = min(res, tmp)

print(res)