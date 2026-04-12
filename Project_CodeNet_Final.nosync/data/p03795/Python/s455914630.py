if __name__ == '__main__':
    n = int(input())
    pay = 800 * n
    ret = 200 * (n // 15)
    print(pay - ret)
