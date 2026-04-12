def resolve():
    X, Y, Z = map(int, input().split())
    ans = 0
    while ans*Y+(ans+1)*Z <= X:
        ans += 1
    print(ans-1)
resolve()