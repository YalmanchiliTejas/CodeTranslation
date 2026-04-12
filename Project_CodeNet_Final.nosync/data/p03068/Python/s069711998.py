n = int(input())
s = input()
k = int(input())

slist = list(s)
char = slist[k-1]

print(''.join([c if c == char else '*' for c in slist]))
