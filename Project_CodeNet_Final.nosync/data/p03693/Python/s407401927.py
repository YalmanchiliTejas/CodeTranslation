def main(a, b, c):
    if (a * 100 + b * 10 + c) % 4 == 0:
        print('YES')
    else:
        print('NO')


a, b, c = [int(i) for i in input().split()]
main(a, b, c)