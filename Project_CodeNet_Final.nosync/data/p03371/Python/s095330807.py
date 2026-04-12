INF = int(1e5)+5

def main():
    a, b, c, x, y = map(int, input().split())
    ans = INF*INF
    for i in range(INF):
        tmp = 2*i*c + a*max(x-i, 0) + b*max(y-i, 0) 
        ans = min(tmp, ans)
    print(ans)
main()
