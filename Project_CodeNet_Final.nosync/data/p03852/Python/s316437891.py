def execute(c):
    return 'vowel' if c in 'aiueo' else 'consonant'


if __name__ == '__main__':
    print(execute(input()))
