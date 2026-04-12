
def read_input():
    r, g, b = map(int, input().split())

    return r, g, b

def submit():
    r, g, b = read_input()

    check = (r*100 + g*10 + b) % 4
    if check:
        print('NO')
    else:
        print('YES')


if __name__ == '__main__':
    submit()