n = int(input())
s = input()
k = s[int(input()) - 1]

for i in s:
    if i != k:
        print('*', end='')
    else:
        print(i, end='')

print()
