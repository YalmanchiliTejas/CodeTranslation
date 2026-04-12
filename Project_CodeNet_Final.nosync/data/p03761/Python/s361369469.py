N = int(input())
s = [input() for i in range(N)]

alphabets = 'abcdefghijklmnopqrstuvwxyz'

ans = ''
for c in alphabets:
    min_count = float('inf')
    for s_i in s:
        count = s_i.count(c)
        if count < min_count:
            min_count = count
    ans += c * min_count
print(ans)