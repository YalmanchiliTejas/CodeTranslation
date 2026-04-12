def solve():
    n = int(input())
    a = list(map(int, input().split()))
    ruiseki = [a[0]]
    for i in range(1,n):
        ruiseki.append(a[i]+ruiseki[i-1])
    ans = 0
    for i in range(n):
        ans += a[i]*(ruiseki[-1]-ruiseki[i])
    print(ans % (10**9+7))
    return 0

if __name__ == "__main__":
    solve()
