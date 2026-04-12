from collections import deque
while 1:
    n,a,b,c,x = map(int,input().split())
    if n == 0 and a == 0 and b == 0 and c == 0 and x == 0:
        break
    y = list(map(int,input().split()))
    flame = 0
    ind = 0
    for i in range(10000+1):
        if x == y[ind]:
            ind += 1
        if ind == n:
            break
        flame += 1
        x = (a*x+b) % c 
    if ind == n:
        print(flame)
    else:
        print(-1)
