moji_list =sorted(list('abcdefghijklmnopqrstuvwxyz'))
n = int(input())
S = [input() for i in range(n)]
moji_con = [0] * len(moji_list)
ans = ''

for i in range(len(moji_list)):
    MM = []
    moji = moji_list[i]
    
    for word in S:
        MM.append(word.count(moji))
    
    moji_con[i] = min(MM)
    
for i in range(len(moji_con)):
    if moji_con[i] != 0:
        ans += moji_con[i]*moji_list[i]
print(ans)