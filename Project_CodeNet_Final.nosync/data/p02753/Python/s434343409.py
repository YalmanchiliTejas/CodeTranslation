def Main(S):
    return 'No' if S == 'AAA' or S == 'BBB' else 'Yes'

def main():
    S = str(input())
    print(Main(S))

if __name__ == '__main__':
    main()