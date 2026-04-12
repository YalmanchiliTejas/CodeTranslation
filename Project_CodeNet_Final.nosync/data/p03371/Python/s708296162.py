

def read_input():
    a, b, c, x, y = map(int, input().split())
    return a, b, c, x, y


def submit():
    a, b, c, x, y = read_input()


    # ABピザをmin(x,y)まで買い、あとは個別
    p1 = 0
    if x < y:
        ab_n = 2 * x
        b_n = y - x
        p1 = b*b_n + ab_n*c
    else:
        ab_n = 2 * y
        a_n = x - y
        p1 = a*a_n + ab_n*c

    # A, Bを別々に買ったほうがいい
    p2 = a*x + b*y

    # 全部ABピザ
    p3 = c * max(x, y)*2

    print(min(p1, p2, p3))

if __name__ == '__main__':
    submit()