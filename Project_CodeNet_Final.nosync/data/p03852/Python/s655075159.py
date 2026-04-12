# -*- coding: utf-8 -*-

def main():

    c = input()

    listVowel = ['a', 'i', 'u' ,'e', 'o']

    if c in listVowel:
        ans = 'vowel'

    else:
        ans = 'consonant'

    print(ans)


if __name__ == "__main__":
    main()