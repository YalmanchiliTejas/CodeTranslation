#-*-coding:utf-8-*-

def main():
    arry = list(input().split())
    i = int(''.join(arry))
    if i % 4 == 0:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()