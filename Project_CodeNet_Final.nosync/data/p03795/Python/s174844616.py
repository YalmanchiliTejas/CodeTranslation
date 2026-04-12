
def read_input():
    x = int(input())
    return x

def submit():
    x = read_input()

    bonus = x // 15
    print(x * 800 - bonus * 200)


if __name__ == '__main__':
    submit()
