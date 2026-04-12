if __name__ == '__main__':
    while 1:
        n,a,b,c,x = list(map(int,input().strip().split()))
        if n ==0 and a == 0 and b ==0 and c ==0 and x ==0:break
        dataline = list(map(int,input().strip().split()))
        f =0
        count = 0
        while 1:
            if x == dataline[count]:count +=1
            if count == n: break
            f +=1
            x = (a * x + b) % c
            if f > 10000:
                f = -1
                break

        print(f)