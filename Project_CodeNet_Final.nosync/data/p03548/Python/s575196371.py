
def read_input():
    x, y, z = map(int, input().split())
    return x, y, z


def submit():
    x, y, z = read_input()

    # z + n (y + z) < xとなる最大のnを見つければよい
    # n < (x - z) / (y + z)

    print((x - z) // (y + z))

if __name__ == '__main__':
    submit()