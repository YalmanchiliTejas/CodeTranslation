

def main():
    n,x,m = map(int,input().split())
    a = [0] * m
    b = [x]
    ans = x
    i = 1
    while i < n:
        x = (x*x) % m
        if x == 0:
            print(ans)
            exit()

        if a[x] == 0:
            a[x] = i
            b.append(x)
            ans += x
            i += 1
        else :
            q = len(b) - a[x]
            qq = (n-len(b)) // q
            qqq = (n-len(b)) % q
            ans += sum(b[a[x]:]) * qq
            ans += sum(b[a[x]:a[x]+qqq])
            #print(b + b[a:] * qq + b[a:a+qqq])
            print(ans)
            exit()

    print(ans)

if __name__ == '__main__':
    main()