
def main():
    n = int(input())
    a = list(map(int,input().split()))

    ans = 0
    m = 0
    for i in a:
        if m <= i:
            ans += 1
        m = max(m,i)

    print(ans)








main()