def ABC_158_A():
    S = input()

    if S.count(S[0]) == 3:
        print('No')
    else:
        print('Yes')


if __name__ == '__main__':

    ABC_158_A()