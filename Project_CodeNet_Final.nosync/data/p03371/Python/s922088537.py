def half_and_half(a,b,c,x,y):
    z = x   if x > y else y
    can = []
    
    for n in range(z+1):
        p = x - n if x > n else 0
        q = y - n if y > n else 0
        amount = p*a + q*b + n*c*2
        #print("%d = %d x %d + %d x %d + %d x %d " %(amount,p,a,q,b,n,c))
        can.append(amount)

    return min(can)

if __name__ == '__main__':
    a,b,c,x,y = map(int,input().split())
    print(half_and_half(a,b,c,x,y))
