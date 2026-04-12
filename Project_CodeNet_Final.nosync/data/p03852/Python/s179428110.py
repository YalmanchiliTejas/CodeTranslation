si = lambda: input()
ni = lambda: int(input())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))
c = si()
b = ('a','i','u','e','o')

if c in b:
    print('vowel')
else:
    print('consonant')


