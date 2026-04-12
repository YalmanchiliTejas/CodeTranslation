N = input()
char_list = list(N)

if char_list[0] == char_list[1] and char_list[1] == char_list[2]:
    print('No')
else:
    print('Yes')