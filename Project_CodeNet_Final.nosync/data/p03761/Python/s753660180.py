from collections import Counter

N = int(input())

strings = [input() for i in range(N)]

string_set = list(map(set,strings))
count_set = list(map(Counter, strings))

common_letter = string_set[0]

for s in string_set:
    common_letter = common_letter & s

common_letter_nums = {}

for l in common_letter:
    common_letter_nums.setdefault(l, [])
    for c in count_set:
        common_letter_nums[l].append(c[l])

output_letter = ''
for k, v in common_letter_nums.items():
    output_letter += k * min(v)

print(''.join(sorted(output_letter)))