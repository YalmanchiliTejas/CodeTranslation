import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

def main():
    A,B,C,x,y = map(int, readline().split())

    ans = 0
    if A + B > C * 2:
        ans += min(x, y) * C * 2
        if x > y:
            ans += (x - y) * min(A, C*2)
        else:
            ans += (y - x) * min(B, C*2)
    
    else:
        ans += A * x + B * y
    
    print(ans)


if __name__ == "__main__":
    main()
