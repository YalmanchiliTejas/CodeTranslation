def resolve():
    S = input()

    S_list = list(S)

    if S == 'AAA' or S == 'BBB':
        print('No')
        return

    print('Yes')
    return

if __name__ == "__main__":
    resolve()