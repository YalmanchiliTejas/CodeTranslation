import sys
def qwe(n,x,ans):
    n1 = "BPPPB"
    n2 = "BBPPPBPBPPPBB"
    if n==1:
        for s in n1:
            if s=="P": ans+=1
            x-=1
            if x==0:
                print(ans)
                sys.exit()
    else:
        for s in n2:
            if s=="P": ans+=1
            x-=1
            if x==0:
                print(ans)
                sys.exit()

def main():
    n,x = map(int, input().split())
    if n<=2:
        qwe(n,x,0)
    a = [1]
    b = [1]
    for i in range(n-1):
        a.append(2*a[-1]+3)
        b.append(2*b[-1]+1)
    ans = 0
    if x== 2*a[n-1]+3:
        print(2*b[n-1]+1)
        sys.exit()
    elif x==2*a[n-1]+2:
        print(2*b[n-1]+1)
        sys.exit()
    elif x == a[n-1]+2:
        print(b[n-1]+1)
        sys.exit()
    elif x== a[n-1]+1:
        print(b[n-1])
        sys.exit()
    elif x > a[n-1]+2:
        ans += b[n-1]+1
        x -= a[n-1]+2
        n = n-1
    else:
        x -=1
        n = n-1
    while n>2 or x > 0:
        if x== 2*a[n-1]+3:
            ans += 2*b[n-1]+1
            print(ans)
            sys.exit()
        elif x==2*a[n-1]+2:
            ans += 2*b[n-1]+1
            print(ans)
            sys.exit()
        if x == a[n-1]+2:
            ans += b[n-1]+1
            print(ans)
            sys.exit()
        elif x== a[n-1]+1:
            ans+=b[n-1]
            print(ans)
            sys.exit()
        elif x > a[n-1]+2:
            ans += b[n-1]+1
            x -= a[n-1]+2
            n = n-1
        else:
            x -=1
            n = n-1
    if x==0:
        print(ans)
        sys.exit()
    qwe(n,x,ans)
if __name__ == "__main__":
    main()