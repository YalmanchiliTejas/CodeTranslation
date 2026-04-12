#python3
INF = int(1e9)
def main():
    a, b, c, x, y = map(int, input().split())
    ans = INF
    for k in range(10**5+10):
        tmp = 2*c*k + max(x-k, 0)*a + max(y-k, 0)*b
        ans = min(ans, tmp)
    print(ans)
main()
