def main():
    r,g,b = (input().split())
    print('YES' if int(g+b)%4==0 else 'NO')

if __name__ == '__main__':
    main()