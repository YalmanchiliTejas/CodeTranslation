n = int(input())
abc = [float('inf')]*26
for i in range(n):
    s = input()
    tmp = [0]*26
    for c in s:
        tmp[ord(c)-ord('a')] += 1
    for j in range(26):
        abc[j] = min(abc[j],tmp[j])

res = ''
for i in range(26):
    res += chr(i+ord('a')) * abc[i]
print(res)
