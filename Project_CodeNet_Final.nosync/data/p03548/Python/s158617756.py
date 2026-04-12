def test():
    x,y,z = map(int,input().split())
    x -= 2*z
    count = 0
    while(x >= y):
        x -= (z+y)
        count += 1
    print(count)


if __name__ == "__main__":
    test()
