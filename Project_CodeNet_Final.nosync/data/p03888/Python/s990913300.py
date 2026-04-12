def main():
    r1, r2 = map(int, input().split())
    return r1 * r2 / (r1 + r2)

if __name__ == '__main__':
    print(main())
