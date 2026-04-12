def resolve():
    S = input()

    vowel = ['a', 'i', 'u', 'e', 'o']

    for ob in vowel:
        if S.startswith(ob):
            print('vowel')
            return

    print('consonant')


if __name__ == '__main__':
    resolve()
