def main():
    from sys import stdin
    r = stdin.readline()[:-1]
    #r = stdin.readlines()

    if r in ('3','5','7'):
        print('YES')
    else:
        print('NO')
   
if __name__ == '__main__':
    main()

