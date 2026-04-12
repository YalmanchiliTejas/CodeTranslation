import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    c = input()
    str = ['a', 'i', 'u', 'e', 'o']
    if c in str:
        print('vowel')
    else:
        print('consonant')

if __name__ == '__main__':
    main()