input_s = str(input())
[n, k] = list(map(int, input_s.split(' ')))
m = []
for i in range(0, n):
    tmp = str(input())
    if tmp.find('#') > -1:
        m.append(tmp)
ta = []
for i in range(0, k):
    tmp = ''
    for j in m:
        tmp += j[i]

    ta.append(tmp)
tb = []
for i in ta:
    if i.find('#') > -1:
        tb.append(i)

result = []
for i in range(0, len(tb[0])):
    tmp = ''
    for j in tb:
        tmp += j[i]
    result.append(tmp)

for i in result:
    print(i)
