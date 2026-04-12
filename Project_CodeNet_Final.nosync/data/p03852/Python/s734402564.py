def solve():
    c = input()
    vowel = ['a', 'e', 'i', 'o', 'u']
    if c in vowel:
        print('vowel')
    else:
        print('consonant')


if __name__ == "__main__":
    solve()