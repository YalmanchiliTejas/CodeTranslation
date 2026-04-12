a,b,c,x,y = map(int, input().split())

if(x < y):
    x,y = y,x
    a,b = b,a

result = 5000*5000*200000
ab = 0
while(x >= 0):
    tmp = x * a + y * b + ab*c
    if(result > tmp):
        result = tmp
    x -= 1
    if(y > 0):
        y -= 1
    ab += 2

print(result)