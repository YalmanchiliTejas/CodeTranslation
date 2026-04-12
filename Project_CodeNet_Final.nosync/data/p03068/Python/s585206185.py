n = int(input())
s = input()
k = int(input())
c = s[k-1]
for i in s:
    if i != c:
        print('*', end='')
    else:
        print(i, end='')
print("")