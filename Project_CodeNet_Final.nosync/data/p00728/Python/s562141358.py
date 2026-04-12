import math
while True:
    x = int(input())
    if x == 0:
        break
    a = list(int(input()) for i in range(x))
    
    a.sort()
    del a[0]
    del a[-1]
    
    b= sum(a)/len(a)
    print(math.floor(b))
