import re
N = int(input())
S = input()
K = int(input())
replace_char = S[K-1]
print(re.sub("[^{}]".format(replace_char), "*", S))