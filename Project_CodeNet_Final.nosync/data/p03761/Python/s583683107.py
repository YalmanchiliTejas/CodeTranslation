ch_dic = {}
n = int(input())
word_list = []
for i in range(n):
    word_list.append(input())
for ch in word_list[0]:
    if ch not in ch_dic:
        ch_dic[ch] = 1
    else:
        ch_dic[ch] += 1

for i in range(1,n):
    ch_list = word_list[i]
    chs = {}
    for ch in ch_list:
        if ch not in chs:
            chs[ch] = 1
        else:
            chs[ch] += 1
    
    for key in ch_dic.copy().keys():
        if key in chs:
            ch_dic[key] = min(chs[key],ch_dic[key])
        else:
            del ch_dic[key]
out = ""
for key,value in ch_dic.items():
    out += key*value
print("".join(sorted(out)))