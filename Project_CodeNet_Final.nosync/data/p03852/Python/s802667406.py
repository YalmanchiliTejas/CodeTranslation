def main():
    c = input()
    vowels = set(iter('aeiou'))
    if c in vowels:
        print('vowel')
    else:
        print('consonant')


if __name__ == '__main__':
    main()
