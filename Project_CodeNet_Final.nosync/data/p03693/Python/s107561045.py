def resolve():
    a, b, c = map(int, input().split())
    x = b*10 + c

    ans = str()
    if x % 4 == 0:
        ans = "YES"
    else:
        ans = "NO"
    print(ans)
resolve()