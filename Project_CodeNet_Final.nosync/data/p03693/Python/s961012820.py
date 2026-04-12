# -*- coding: utf-8 -*-

def main():
    r, g, b = map(str, input().split())
    print('YES' if int(r+g+b)%4 == 0 else 'NO')

if __name__ == '__main__':
    main()