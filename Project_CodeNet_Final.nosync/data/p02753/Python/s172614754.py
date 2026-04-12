# -*- coding: utf-8 -*-

def main():

    S = input()
    listS = S.split()

    if S[0] == S[1] and S[1] == S[2]:
        ans = 'No'

    else:
        ans = 'Yes'

    print(ans)


if __name__ == "__main__":
    main()