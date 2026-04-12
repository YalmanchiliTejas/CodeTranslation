from collections import defaultdict
n = int(input())
dicts = []
sets = []
da = dicts.append
for i in [input() for _ in range(n)]:
    tmp_dict = defaultdict(lambda: 0)
    for j in i:
        tmp_dict[j] += 1
    da(tmp_dict)

intersection = set(dicts[0].keys())
for i in dicts[1:]:
    intersection = intersection & i.keys()
final_words = ''
for i in sorted(list(intersection)):
    tmp = 100
    for j in dicts:
        t = j[i]
        if t < tmp:
            tmp = t
    final_words += i*tmp
print(final_words)