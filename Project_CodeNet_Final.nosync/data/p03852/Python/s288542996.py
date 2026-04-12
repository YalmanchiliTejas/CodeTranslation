import sys

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

def solve():
    c = input()
    boin = {'a', 'e', 'i', 'o', 'u'}

    if c in boin:
        ans = 'vowel'
    else:
        ans = 'consonant'

    print(ans)


if __name__ == '__main__':
    solve()