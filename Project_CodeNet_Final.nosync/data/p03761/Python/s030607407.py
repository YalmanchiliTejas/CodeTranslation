n = int(input())
li = [[0]*n for i in range(26)]
for i in range(n):
    S = list(input())
    for x in S:
        li[ord(x)-97][i] += 1
ans = []
for i in range(26):
    num = min(li[i])
    ans += [chr(i+97)] * num
print(''.join(ans))