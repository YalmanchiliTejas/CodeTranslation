N = int(input())

all_dict = dict()
s = str(input())
for i in range(len(s)):
    if s[i] in all_dict:
        all_dict[s[i]] += 1
    else:
        all_dict[s[i]] = 1
        
for i in range(N-1):
    s = str(input())
    s_dict = dict()
    for j in range(len(s)):
        if s[j] in s_dict:
            s_dict[s[j]] += 1
        else:
            s_dict[s[j]] = 1
            
    and_key = all_dict.keys() & s_dict.keys()
    tmp_dict = dict()
    and_key = list(and_key)
    for j in range(len(and_key)):
        tmp_dict[and_key[j]] = min(all_dict[and_key[j]], s_dict[and_key[j]])
    all_dict = tmp_dict
    
all_dict = sorted(all_dict.items(), key=lambda x:x[0])

for i in range(len(all_dict)):
    for j in range(all_dict[i][1]):
        print(all_dict[i][0], end="")