n = int(input())
a = list(map(int,input().strip().split()))


m = 10 ** 9 + 7
def main():
    s = sum(a)
    ss = 0
    r = 0
    for nn in range(n):
        ss += a[nn]
        r += a[nn] * (s - ss)
    print(r % m)
    return

main()
