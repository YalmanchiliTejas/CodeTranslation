def bench(x,y,z):
    return (x-z) // (y+z)

if __name__ == '__main__':
    x,y,z = map(int, input().split())
    print(bench(x,y,z))
    