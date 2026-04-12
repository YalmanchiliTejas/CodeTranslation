import re
N = int(input())
S = input()
K = int(input())

for s in S:
    if s == S[K-1]:
        print(s, end="")
    else:
        print('*', end="")
    
print('')