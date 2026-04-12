def solve():
    A,B,C,X,Y = map(int, input().split())
    ans = X*A + Y*B
    for i in range(max(X,Y)+1):
        aandb = A * max(0, X-i) + B * max(0, Y-i)
        ab = 2*C*i
        ans = min(ans, aandb + ab)
    print(ans)

if __name__ == '__main__':
    solve()