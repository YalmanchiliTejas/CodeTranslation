import re

N = int(input())
S = str(input())
K = int(input())

char = S[K-1]
temp = S.replace(S[K-1], '|')
temp2 = re.sub(r"\w", "*", temp)
print(temp2.replace('|', char))