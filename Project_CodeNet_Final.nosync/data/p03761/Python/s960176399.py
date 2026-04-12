n = int(input())
s = []
for i in range(0, n):
    s.append(input())

final_list = [0 for i in range(26)]
for i, si in enumerate(s):
    char_list = [0 for i in range(26)]
    for char in si:
        char_list[ord(char)-97] += 1
    if i == 0:
        final_list = char_list
    else:
        final_list = [min(char_list[i], final_list[i]) for i in range(26)]

result = ''
for i in range(26):
    if final_list[i] != 0:
        for j in range(final_list[i]):
            result += chr(97+i)

print(result)