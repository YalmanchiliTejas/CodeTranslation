N = int(input())
S = input()
K = int(input())
target = S[K-1]
result = []
result2 = ''
for i in S:
    if i is target:
        result.append(i)
    else:
        result.append('*')
for i in result:
    result2 += i

print(result2)