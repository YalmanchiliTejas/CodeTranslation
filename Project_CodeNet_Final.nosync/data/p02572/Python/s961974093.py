def main():

    n = int(input())
    a = list(map(int,input().split()))


    m = 10**9 + 7
    ans = 0
    s = []
    total = sum(a)
    s.append(total-a[0])
    for i in range(1,n):
        s.append(s[i-1] - a[i])
    for i in range(n):
        tmp = s[i] % m
        ans += tmp * a[i]
    # ans //= 2
    print(ans%m)

if __name__=='__main__':
    main()
