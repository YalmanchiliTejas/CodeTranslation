



def main():

    A,B,C,X,Y = map(int,input().split())
    cSet = 2*C

    if X == Y:
        price = min(cSet*X, A*X+B*Y)
    elif X > Y:
        price = min(cSet*X, cSet*Y+A*(X-Y), A*X+B*Y)
    else:
        price = min(cSet*Y, cSet*X+B*(Y-X), A*X+B*Y)
    
    print(price)



 





if __name__ == "__main__":
    main()