
def main():

    a,b,c,x,y = map(int, input().split())
    if x>y:
        if a+b>c*2:
            if a>c*2:
                print(c*2*x)
            else:
                print(c*2*y+a*(x-y))
        else:
            if a>c*2:
                print((a+b)*y+c*2*(x-y))
            else:
                print((a+b)*y+a*(x-y))
    elif x<y:
        if a+b>c*2:
            if b>c*2:
                print(c*2*y)
            else:
                print(c*2*x+b*(y-x))
        else:
            if b>c*2:
                print((a+b)*x+c*2*(y-x))
            else:
                print((a+b)*x+b*(y-x))
    else:
        if a+b>c*2:
            print(c*2*x)
        else:
            print((a+b)*x)


    
if __name__ == '__main__':
    main()