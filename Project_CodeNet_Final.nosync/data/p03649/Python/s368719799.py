def main():
    import sys,math
    input = sys.stdin.readline

    n = int(input())
    a = list(map(int,input().split()))

    res = 0
    judge = True
    for e in a:
        if e >= n:
            judge = False
            break
    if judge:
        print(res)
        return
    
    x = 0
    while True:
        if a[x] <= n-1:
            x += 1
            if x == n:
                x = 0
            continue

        p = (a[x]//n)
        a[x] -= p*n
        res += p

        judge = True
        for i in range(n):
            if i == x:
                continue
            a[i] += p
            if a[i] >= n:
                judge = False
        if judge:
            print(res)
            return
        
        x += 1
        if x == n:
            x = 0

if __name__ == '__main__':
    main()