n = int(input())
S = [input() for _ in range(n)]
alphabet_str = "abcdefghijklmnopqrstuvwxyz"
alphabets = list(alphabet_str)

s_maps = []
for s in S:
    strs = list(s)
    m = {}
    for alphabet in alphabets:
        m[alphabet] = 0
    for _str in strs:
        m[_str] += 1
    s_maps.append(m)

ans = ""
for alphabet in alphabets:
    min_num = 51
    for s_map in s_maps:
        min_num = min(s_map[alphabet], min_num)
    for i in range(min_num):
        ans = ans + alphabet
print(ans)
