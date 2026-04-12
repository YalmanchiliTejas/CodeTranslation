import sys
readline = sys.stdin.readline
intin = map( int, readline().rstrip().split() )

a , b ,c , x , y  = intin

times = max(x,y)

total = 0
for t in range(times):
    if x > 0 and y > 0 :
        if a + b >= 2 * c :
            total += 2 * c
            x -= 1
            y -= 1
            continue
        else:
            total += a+b
            x -= 1 
            y -= 1
            continue
    elif x > 0 and y <= 0 :
        if a > 2 * c :
            total += 2 * c
            x -= 1
            continue
        else:
            total += a
            x -= 1
            continue
    elif y > 0 and x <= 0 :
        if b > 2 * c :
            total += 2 * c
            y -= 1
            continue
        else:
            total += b
            y -= 1
            continue
    else:
        break

print(total)