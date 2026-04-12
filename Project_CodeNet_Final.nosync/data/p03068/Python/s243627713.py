n = input()
s = list(input())
k = int(input())

sub = s[k-1]

for i in range(len(s)):
    if s[i] != sub:
        s[i] = '*'

print(''.join(s))