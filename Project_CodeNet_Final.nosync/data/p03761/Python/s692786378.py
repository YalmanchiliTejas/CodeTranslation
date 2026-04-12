import sys

n = int(sys.stdin.readline().strip())
str_list = []

common_char = set()

for i in range(n):
    line = sys.stdin.readline().strip()
    str_list.append(list(line))

    char_set = set(line)
    if len(common_char) == 0:
        common_char = char_set
    else:
        common_char = common_char.intersection(char_set)

#print(str_list)
#print(common_char)

ans_str_list = []
for c in common_char:
    min_num = 50
    for sl in str_list:
        min_num = min( min_num, sl.count(c) )
    
    for i in range(min_num):
        ans_str_list.append(c)

ans_str_list.sort()
ans = "".join(ans_str_list)

print(ans)
