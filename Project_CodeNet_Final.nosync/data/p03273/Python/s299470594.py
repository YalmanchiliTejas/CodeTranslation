h, w = map(int, input().split())
ls_a = [[_ for _ in input()] for _ in range(h)]

memo = []

for i in range(h):
    if ls_a[i] != ["."] * w:
        memo.append(ls_a[i])

ls = [["" for _ in range(len(memo))] for _ in range(w)]

for i in range(w):
    for j in range(len(memo)):
        ls[i][j] = memo[j][i]

memo = []

for i in range(w):
    if ls[i] != ["."] * len(ls[i]):
        memo.append(ls[i])

ans = [["" for _ in range(len(memo))] for _ in range(len(memo[0]))]

for i in range(len(memo[0])):
    for j in range(len(memo)):
        ans[i][j] = memo[j][i]


for i in range(len(ans)):
    print("".join(ans[i]))