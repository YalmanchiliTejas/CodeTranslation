import re

N = int(input())
S = input()
K = int(input())

key = S[K - 1]

print(re.sub("[^" + key + "]", "*", S))