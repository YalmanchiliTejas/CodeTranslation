a,b,c = map(int,input().split())
x = 1

while a >= b*x + c*(x+1):
    x += 1

print(x-1)
