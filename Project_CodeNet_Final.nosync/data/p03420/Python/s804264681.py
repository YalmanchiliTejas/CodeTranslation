def main():
    n,k = map(int,input().split())
    res = 0

    if k == 0:
        print(n ** 2)
    else:
        for b in range(k+1,n+1):
            res += (b-k) * (n//b)
            if n % b != 0:
                res +=max(0, n - ((n//b)*b+k) +1)
        print(res)
main()