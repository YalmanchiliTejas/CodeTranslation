def main():
    a,b,ab,ac,bc = map(int,input().split())
    price = 0
    if a+b < ab*2:
        price = a*ac + b*bc
    else:
        if ac < bc:
            price += ab*ac*2
            x = bc-ac
            price += min(x*b, x*ab*2)
        else:
            price += ab*bc*2
            x = ac-bc
            price += min(x*a, x*ab*2)
    print(price)

if __name__ == "__main__":
    main()