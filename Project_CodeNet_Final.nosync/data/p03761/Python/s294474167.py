n = int(input())
cnt_dict = []
for _ in range(n):
    input_str = input()
    chr_dict = {chr(i):0 for i in range(97,97+26)}
    for s in input_str:
        chr_dict[s] += 1
    cnt_dict.append(chr_dict)

common = {chr(i):100 for i in range(97,97+26)}
for c in cnt_dict:
    for k,v in c.items():
        common[k] = min(common[k],v)

result = ''
for k,v in sorted(common.items()):
    result += k*v
print(result)
