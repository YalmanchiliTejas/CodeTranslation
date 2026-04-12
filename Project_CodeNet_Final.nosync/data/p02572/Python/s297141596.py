def main():
    n = int(input())
    arr = list(map(int, input().split()))

    pref = []

    dup = arr.copy()
    dup.reverse()

    pref.append(dup[0]);
    
    for i in range(1,n):
       pref.append(pref[i-1]+dup[i]);
    
    pref.reverse()

    ans = 0

    for i in range(n-1):
        ans += arr[i] * pref[i+1];

    ans %= 1000000007;

    print(ans)


if __name__ == '__main__':
    main();
