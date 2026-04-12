import re

N = int(input())
S = str(input())
K = int(input())

listS = list(S)
result = re.sub('[^'+listS[K-1]+']', '*', S)
print(result)
