n = int(input())
s = input()
k = int(input())

i = s[k-1]
l = [c if c == i else '*' for c in s ]
print(''.join(l))