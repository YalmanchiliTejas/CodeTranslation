def solve():
    a,b,c,x,y = map(int, input().split())
    z = [a*x + b*y, c*2*x + b*max(0,y-x), c*2*y + a*max(0,x-y), c*2*max(x,y)]
    return min(z)
        
if __name__ == '__main__':
    print(solve())