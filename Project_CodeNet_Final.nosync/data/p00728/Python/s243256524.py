while True:
    n = int(input())
    if n == 0: break
    src = [int(input()) for i in range(n)]
    ans = (sum(src) - max(src) - min(src)) // (n-2)
    print(ans)