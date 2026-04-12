n = int(input())
s = input()
k = int(input())

lst_s = list(s)
for i, si in enumerate(s):
    if si != s[k-1]:
        lst_s[i] = '*'

print(''.join(lst_s))