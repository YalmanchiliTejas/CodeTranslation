def p(n):
    return (2**(n+1) - 1)

def h(n):
    return (2**(n+2) - 3)

def lune(n,x):
    if n == 0 and x > 0:
        return 1
    for i in range(1,n+1):
        if x > h(n-i) + i:
            return (p(n-i) + 1 + lune(n-i, x - (h(n-i) + i) - 1))
    if x > n:
        return 1
    else:
        return 0

def main():
    n,x = map(int, input().split())
    if x >= (h(n) + 1) // 2:
        print(p(n) - lune(n, h(n) - x))
    else:
        print(lune(n,x))

if __name__ == "__main__":
    main()