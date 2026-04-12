def test():
    a,b,c,x,y = map(int,input().split())
    result = float("inf")
    for i in range(x+y):
        result = min(result,2*c*i + a*max(0,x-i) + b*max(0,y-i))
    print(result)


if __name__ == "__main__":
    test()
