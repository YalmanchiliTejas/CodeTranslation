n = int(input())
S = [input() for i in range(n)]

counter = [{} for i in range(n)]
ascii_lowercase = 'abcdefghijklmnopqrstuvwxyz'

for i in range(n):
    for alphabet in ascii_lowercase:
        counter[i][alphabet] = S[i].count(alphabet)

tmp = {}
for alphabet in ascii_lowercase:
    tmp[alphabet] = 99999999

for alphabet in ascii_lowercase:
    for i in counter:
        tmp[alphabet] = min(tmp[alphabet], i[alphabet])

tmp = sorted(tmp.items(), key=lambda x:x[0])
for i in tmp:
    for j in range(0,i[1]):
        print(i[0], end="")