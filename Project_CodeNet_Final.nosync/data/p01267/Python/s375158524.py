def main():
    while True:
        n,a,b,c,x = map(int,input().split())
        if (n,a,b,c,x) == (0,0,0,0,0):
            return
        yy = list(map(int,input().split()))
        yi = 0
        for i in range(10002):
            if yi == len(yy):
                print(i-1)
                break
            elif i > 10000:
                print(-1)
                break
            if x == yy[yi]:
                yi += 1
            x = (a * x + b) % c

if __name__ == '__main__':
    main()

