n = int(input())
s_list = list(input() for _ in range(n))

alphabets = 'abcdefghijklmnopqrstuvwxyz'

ans = ""
for x in alphabets:
    min_count = float('inf')
    for s in s_list:
        count = s.count(x)
        min_count = min(min_count, count)
        if min_count == 0:
            break
    ans += x * min_count
print(ans)