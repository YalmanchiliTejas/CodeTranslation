nl = lambda: list(map(int, input().split()))
sl = lambda: input().split()
n = lambda: int(input())
s = lambda: input()

c = s()
if c in 'aiueo':
    print('vowel')
else:
    print('consonant')
