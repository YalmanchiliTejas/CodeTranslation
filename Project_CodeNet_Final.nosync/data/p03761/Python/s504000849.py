from collections import Counter
n = int(input())
alphabet_ls = [chr(i) for i in range(97, 97+26)]
alphabet_dict = {alphabet:float('inf') for alphabet in alphabet_ls}
for i in range(n):
    s = input()
    c = Counter(s)
    for alphabet, before in alphabet_dict.items():
        if alphabet not in c.keys():
            alphabet_dict[alphabet] = 0
        else:
            if c[alphabet] < before:
                alphabet_dict[alphabet] = c[alphabet]
sorted_ls = sorted(alphabet_dict.items())
ans_ls = []
for alphabet, count in sorted_ls:
    for _ in range(count):
        ans_ls.append(alphabet)
ans = ''.join(ans_ls)
print(ans)
