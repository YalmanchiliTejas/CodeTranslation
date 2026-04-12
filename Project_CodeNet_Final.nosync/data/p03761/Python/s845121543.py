import string
from collections import Counter
n = int(input())
S = [input() for _ in range(n)]
S_set = [set(list(l)) for l in S]
char_set = set(list(string.ascii_lowercase))
for sub in S_set:
    char_set = char_set & sub
if char_set == set([]):
    print('')
else:
    enable_charset = {c: 99 for c in char_set}
    for sent in S:
        counter = Counter(sent)
        for c in enable_charset.keys():
            enable_charset[c] = min(enable_charset[c], counter[c])
    res = ''
    for k, v in enable_charset.items():
        res += k * v
    print(''.join(sorted(res)))