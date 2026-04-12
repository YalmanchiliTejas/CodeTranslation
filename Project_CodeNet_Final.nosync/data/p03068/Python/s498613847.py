n = int(input())
s = input()
i = int(input())
c = s[i-1]
for ch in s:
    if ch != c:
        print('*', end="")
    else:
        print(ch, end='')