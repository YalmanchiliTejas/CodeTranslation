n = int(input())
dict_lst = []
for _ in range(n):
    input_str = input()
    chr_dict = {chr(i):0 for i in range(97,97+26)}
    for s in input_str:
        chr_dict[s] += 1
    dict_lst.append(chr_dict)

ans_dict = {chr(i):100 for i in range(97,97+26)}
for d in dict_lst:
    for k,v in d.items():
        ans_dict[k] = min(ans_dict[k],v)

ans = ''
for k,v in sorted(ans_dict.items()):
    ans += k*v 
print(ans)
