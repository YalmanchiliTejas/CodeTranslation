check = [chr(i) for i in range(97, 97+26)]
n = int(input())
li = [input() for _ in range(n)]
ans = [0] * 26


for i in range(26):
    cnt = 1000
    for j in range(n):
        cnt = min(cnt, li[j].count(check[i]))
    ans[i] = cnt

char = ''

for x, y in zip(check, ans):
    char += x*y

print(char)