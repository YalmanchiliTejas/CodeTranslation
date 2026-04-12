if __name__ == '__main__':
    a,b,c,x,y = map(int, raw_input().split())
    if c * 2 > a + b:
        print a * x + b * y
    else:
        cost = c * 2 * min(x,y)
        z = abs(x-y)
        if x < y :
            if c * 2 * z < b * z:
                print cost + c * 2 * z
            else:
                print cost + b * z
        else:
            if c * 2 * z < a * z:
                print cost + c * 2 * z
            else:
                print cost + a * z
        
