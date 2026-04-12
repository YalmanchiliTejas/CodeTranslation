n = int(input())
s = input()
k = int(input())

keep_word = s[k-1]
for ss in s:
    if ss == keep_word:
        print(ss, end='')
    else:
        print('*', end='')