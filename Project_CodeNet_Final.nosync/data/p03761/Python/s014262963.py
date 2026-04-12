n = int(input())
alphabetMin = [50]*(26)
for i in range(n):
    tmp = list(input())
    for j in range(ord('a'), ord('z') + 1):
        cnt = tmp.count(chr(j))
        if cnt < alphabetMin[j - ord('a')]:
            alphabetMin[j - ord('a')] = cnt
ans = ''
for i, alpha in enumerate(alphabetMin):
    ans += chr(ord('a') + i) * alpha
print(ans)
