r,g,b = map(int,input().split())

i = 100 * r + 10 * g + b 
if i%4 ==0:
    print('YES')
else:
    print("NO")
    
    