import sys
a = []
for l in sys.stdin:
    a.append(l)


word_num = int(a[0])
word = a[1].split()[0]
char_num = int(a[2])

target_char = word[char_num - 1]

result = []
for each_char in word:
    if each_char != target_char:
        result.append('*')
    else:
        result.append(each_char)
result = ''.join(result)
print(result)
