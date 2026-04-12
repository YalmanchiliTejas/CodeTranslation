import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    x,y,z=map(int, input().split())
    print((x-z)//(y+z))

main()