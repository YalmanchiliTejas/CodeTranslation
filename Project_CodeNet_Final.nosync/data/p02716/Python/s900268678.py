def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    inf = -10**16
    if n%2:
        dp0 = [0]*n
        dp1 = [0]*n
        sumk = a[0]
        dp0[1] = inf
        dp1[1] = max([a[0], a[1]])
        if n > 2:
            dp0[2] = 0
            dp1[2] = max([a[2], dp1[1]])
            sumk += a[2]
        if n > 3:
            dp0[3] = max([dp1[2], a[3]])
            dp1[3] = max([a[0]+a[2], a[0]+a[3], a[1]+a[3]])
        for i in range(4, n):
            if i%2 == 0:
                dp0[i] = max([dp0[i-1], dp0[i-2]+a[i]])
                dp1[i] = max([dp1[i-1], dp1[i-2]+a[i]])
                sumk += a[i]
            else:
                dp0[i] = max([dp1[i-1], dp0[i-2]+a[i]])
                dp1[i] = max([dp1[i-2]+a[i], sumk])
        ans = dp1[n-1]
    else:
        key = sum(a[::2])
        ans = key
        for i in range(n-1, 0, -2):
            key += a[i]
            key -= a[i-1]
            if ans < key:
                ans = key
    print(ans)
            
    
    

if __name__ == "__main__":
    main()