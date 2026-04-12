import re

N = int(input())
S = input()
K = int(input())
test = list(S)
str = ""
for i in test:
    if(i == test[K - 1]):
        str += i
    else:
        str += "*"
print(str)