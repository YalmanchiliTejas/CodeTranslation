def half_and_half(a,b,c,x,y):
    z = x   if x > y else y
    can = []
    
    for n in range(z+1):
        p = x - n if x > n else 0
        q = y - n if y > n else 0
        amount = p*a + q*b + n*c*2
        #print("%d = %d x %d + %d x %d + %d x %d " %(amount,p,a,q,b,n,c))
        can.append(amount)

    #print(sorted(can,reverse=True))
    print(min(can))
    #print('')
if __name__ == '__main__':
    a,b,c,x,y = map(int,input().split())
    #a,b,c,x,y = 1500,2000,1600,3,2
    #print(a,b,c,x,y)
    half_and_half(a,b,c,x,y)
