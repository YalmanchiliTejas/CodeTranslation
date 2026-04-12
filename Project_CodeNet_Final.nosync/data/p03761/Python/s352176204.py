n = int(input())
alphabets = [chr(i) for i in range(97, 97+26)]
alphab_num = {}
for a in alphabets:
    alphab_num[a] = [0]*n
for i in range(n):
    s = input()
    for ss in s:
        alphab_num[ss][i] += 1

ans = ''
for a in alphabets:
    for _ in range(min(alphab_num[a])):
        ans += a
print(ans)