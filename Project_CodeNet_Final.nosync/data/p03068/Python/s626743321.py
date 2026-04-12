n = int(input())
s = input()
k = int(input()) - 1

s = list(map(lambda x: '*' if x != s[k] else x, s))

print(*s, sep='')
