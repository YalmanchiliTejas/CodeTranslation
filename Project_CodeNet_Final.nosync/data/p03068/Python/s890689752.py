n = int(input())
s = input()
k = int(input())

char = s[k-1]

for i in range(n):
    if s[i] == char:
        print(s[i], end='')
    else:
        print('*', end='')