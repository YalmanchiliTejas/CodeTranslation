def read_input():
    c = input().strip()
    return c

def submit():
    c = read_input()

    if c in 'aiueo':
        print('vowel')
    else:
        print('consonant')

if __name__ == '__main__':
    submit()