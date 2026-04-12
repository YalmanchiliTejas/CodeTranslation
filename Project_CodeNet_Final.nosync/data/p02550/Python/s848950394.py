import sys
input = sys.stdin.readline

def main():
    n, x, m = map(int, input().split())
    loop = [x]
    check = [False for _ in range(m + 1)]
    check[x] = True
    x2 = x
    for _ in range(n - 1):
        x2 = x2 ** 2 % m
        if check[x2]:
            break
        check[x2] = True
        loop.append(x2)
    else:
        print(sum(loop))
        return
    pos = loop.index(x2)
    ans = sum(loop[:pos])
    loop2 = loop[pos:]
    l = len(loop2)
    n -= pos
    ans += sum(loop2) * (n // l)
    ans += sum(loop2[:n % l])
    print(ans)
    
    
main()