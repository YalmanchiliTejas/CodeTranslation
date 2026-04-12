import re

N = int(input())
S = str(input())
K = int(input())

T = S[K-1:K]

print(re.sub('[^' + T + ']',"*",S))