def main():
    n,k = map(int,input().split())

    ans = 0
    if k == 0:
        ans = n * n
    else:
        for i in range(k+1,n+1):
            ans += n // i * (i-k)
            ans += max(0,n%i-k+1)
    
    print(ans)

if __name__ == '__main__':
    main()