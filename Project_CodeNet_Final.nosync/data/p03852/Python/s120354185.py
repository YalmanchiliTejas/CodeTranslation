import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    c = input()
    if c in 'aeiou':
        print('vowel')
    else:
        print('consonant')
resolve()