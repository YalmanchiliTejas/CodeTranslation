def main():
    n,x,m = map(int,input().split())
    amari = [0 for i in range(m)]
    x = x%m
    amari[x] = 1
    loop = [x]
    while True:
        x = x**2 % m
        if amari[x]==0:
            loop.append(x)
            amari[x] = 1
        elif x==0:
            loop.append(0)
            if len(loop)>n:
                print(sum(loop))
            else:
                print(sum(loop[0:n]))
            return
        else:
            st = loop[0:loop.index(x)]
            loop = loop[loop.index(x):]
            break
    ans = 0
    if len(st)>=n:
        ans = sum(st[0:n])
        print(ans)
        return
    ans = sum(st)
    l = (n-len(st))//len(loop)
    ans += l*sum(loop)
    for i in range(n-len(st)-l*len(loop)):
        ans += loop[i]
    print(ans)

if __name__ == "__main__":
    main()