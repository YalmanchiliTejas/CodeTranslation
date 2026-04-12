n = int(input())
s = input().rstrip()
k = int(input())

c = s[k - 1]
r = []
for letter in list(s):
    e = '*' if letter is not c else c
    r.append(e)

print(''.join(r))
