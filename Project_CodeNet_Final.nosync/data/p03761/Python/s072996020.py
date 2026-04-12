moji_list =sorted(list('abcdefghijklmnopqrstuvwxyz'))

n = int(input())
S = [0]*n
for  i in range(n):
    S[i] = input()
    
moji_con = [0] * len(moji_list)

for i in range(len(moji_list)):
    MM = []
    moji = moji_list[i]
    
    for word in S:
        MM.append(word.count(moji))
    
    moji_con[i] = min(MM)
    
ans = ''
for i in range(len(moji_con)):
    if moji_con[i] != 0:
        ans += moji_con[i]*moji_list[i]
print(ans)