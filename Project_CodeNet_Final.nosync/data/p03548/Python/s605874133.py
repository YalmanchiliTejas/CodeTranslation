import math

X, Y, Z = map(int, input().split())

def ans(num, max):
    result = math.floor(max / num)
    print("{0}".format(result))

def main():
    max_length = X - Z
    each_space = Y + Z
    ans(each_space, max_length)

main()
