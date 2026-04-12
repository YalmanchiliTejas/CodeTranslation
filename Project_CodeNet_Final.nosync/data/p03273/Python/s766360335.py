import sys
h, w = map(int, sys.stdin.readline().split())
a = [input() for _ in range(h)]
ans_tmp = []
for i in range(h):
    if '#' in a[i]:
        ans_tmp.append(a[i])

not_hash_num = set()
cnt = 0
for i in range(w):
    for j in range(h):
        if a[j][i] == '#':
            break
        if j == h-1:
            cnt += 1
            not_hash_num.add(i)

# print(ans_tmp)
# print(not_hash_num)
ans = [ [] for _ in range(len(ans_tmp))]
# print(ans)

for i in range(w):
    if i in not_hash_num:
        continue
    for j in range(len(ans_tmp)):
        ans[j].append(ans_tmp[j][i])

for i in range(len(ans_tmp)):
    print(''.join(ans[i]))
