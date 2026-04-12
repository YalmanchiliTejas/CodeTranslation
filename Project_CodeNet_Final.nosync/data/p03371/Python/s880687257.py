def main():
    a, b, c, x, y = list(map(int, input().split(" ")))

    ans = 10**10
    for ai in range(x+1):
        ci = (x - ai)*2
        bi = y - ci//2
        if bi<0:
            bi = 0
        cost = a*ai + b*bi + c*ci
        if cost<ans:
            ans = cost

        if ai==0:
            if c*2 < b:
                bi = 0
                ci = max(x, y)*2
                cost = c*ci
                if cost<ans:
                    ans = cost

    print(ans)

if __name__=="__main__":
    main()

