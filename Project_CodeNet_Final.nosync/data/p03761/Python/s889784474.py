N = int(input())
char_dict = {}
s_li = []
ans = ''
for i in range(N):
    s_li.append(input())
for s in s_li:
    for c in [chr(ord('a') + i) for i in range(26)]:
        cnt = s.count(c)
        if c not in char_dict:
            char_dict[c] = cnt
        else:
            char_dict[c] = min(cnt, char_dict[c])
for k, v in char_dict.items():
    ans += k * v
print(ans)
