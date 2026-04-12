def S(): return input().rstrip()

def main():
    s = S()

    if 'A' in s and 'B' in s:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()
