n = int(input())
moji = [chr(i) for i in range(97, 97+26)]
s = [input() for i in range(n)]
ans = ""
for i in moji:
    count = 100
    for j in s:
        count = min(count, j.count(i))
    ans += i*count
print(ans)