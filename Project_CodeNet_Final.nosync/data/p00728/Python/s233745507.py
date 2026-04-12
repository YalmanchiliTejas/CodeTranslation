while(True):
    x = input()
    x= int(x)
    if x==0:
        break
    max_p = 0
    min_p= 1000
    total = 0
    for n in range(x):
        point = input()
        point = int(point)
        total += point
        if max_p < point:
            max_p =  point
        if min_p > point:
            min_p = point
    ans = total - max_p -min_p
    ans /= x-2
    ans = int(ans)
    print(ans)
        
