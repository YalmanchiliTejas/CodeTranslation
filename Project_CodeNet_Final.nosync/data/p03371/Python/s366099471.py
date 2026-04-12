import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip() # ignore trailing spaces 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))

def abc_c095(a,b,c,x,y):
    ab = x*2
    if y - ab//2 > 0:
        return b*(y - ab//2) + c*ab
    else:
        return c*ab

def main():
    a,b,c,x,y = na()
    ans = a*x + b*y
    ans = min(ans, abc_c095(a,b,c,x,y))
    ans = min(ans, abc_c095(b,a,c,y,x))
    print(ans)
    return

if __name__ == '__main__':
    main()
