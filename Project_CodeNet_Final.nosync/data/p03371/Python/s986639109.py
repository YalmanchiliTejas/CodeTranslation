#python3
INF = int(1e9)
def main():
    a, b, c, x, y = map(int, input().split())
    ans = INF
    for i in range(2*10**5+100):
        t = 2*c*i + max(x-i, 0) * a + max(y-i, 0) * b
        ans = min(ans, t)
    print(ans)
main()